// ......................................................
// ..................RTCMultiConnection Code.............
// ......................................................

var roomid = window.location.hash.substr(1);

// just in case; normally this id comes from the pi connecting
if(roomid==""){
    roomid = parseInt(Math.random()*1000)+"";
}

var connection = new RTCMultiConnection();

// by default, socket.io server is assumed to be deployed on your own URL
connection.socketURL = '/';

// this is only useful if we want to do something server side
connection.socketMessageEvent = 'audio-data-video-asymmetric';

connection.onstream = function(event) {
  // don't display local video; this is mostly becaus ethe pi can't handle it
  if(event.type!="local"){
    var video = event.mediaElement;
    document.querySelector('#videos-container').append(video);
  }else{
    console.log("not displaying local stream");
  }
};


//I don't use this stuff but could be handy later
// STAR_FIX_VIDEO_AUTO_PAUSE_ISSUES
// via: https://github.com/muaz-khan/RTCMultiConnection/issues/778#issuecomment-524853468
var bitrates = 512;
var resolutions = 'lower';
var videoConstraints = {};
var audioConstraints = {};

if (resolutions == 'lower') {
  videoConstraints = {
    width: {
      ideal: 640
    },
    height: {
      ideal: 480
    },
    frameRate: 10
  };
}

if (resolutions == 'HD') {
  videoConstraints = {
    width: {
      ideal: 1280
    },
    height: {
      ideal: 720
    },
    frameRate: 30
  };
}

if (resolutions == 'Ultra-HD') {
  videoConstraints = {
    width: {
      ideal: 1920
    },
    height: {
      ideal: 1080
    },
    frameRate: 30
  };
}

connection.mediaConstraints = {
  video: videoConstraints,
  audio: audioConstraints
};

var CodecsHandler = connection.CodecsHandler;

connection.processSdp = function(sdp) {
  var codecs = 'vp8';

  if (codecs.length) {
    sdp = CodecsHandler.preferCodec(sdp, codecs.toLowerCase());
  }

  if (resolutions == 'HD') {
    sdp = CodecsHandler.setApplicationSpecificBandwidth(sdp, {
      audio: 128,
      video: bitrates,
      screen: bitrates
    });

    sdp = CodecsHandler.setVideoBitrates(sdp, {
      min: bitrates * 8 * 1024,
      max: bitrates * 8 * 1024,
    });
  }

  if (resolutions == 'Ultra-HD') {
    sdp = CodecsHandler.setApplicationSpecificBandwidth(sdp, {
      audio: 128,
      video: bitrates,
      screen: bitrates
    });

    sdp = CodecsHandler.setVideoBitrates(sdp, {
      min: bitrates * 8 * 1024,
      max: bitrates * 8 * 1024,
    });
  }

  return sdp;
};
// END_FIX_VIDEO_AUTO_PAUSE_ISSUES

// https://www.rtcmulticonnection.org/docs/iceServers/
// use your own TURN-server here!
connection.iceServers = [{
  'urls': [
     'stun:stun.l.google.com:19302',
     'stun:stun1.l.google.com:19302',
     'stun:stun2.l.google.com:19302',
     'stun:stun.l.google.com:19302?transport=udp',
  ]
}];

createRoom = function() {
  console.log("creating room",roomid);
  connection.open(roomid, function() {
    showRoomURL(connection.sessionid);
  });
};

joinRoom = function() {
  console.log("joining room",roomid);
  connection.join(roomid, function() {
    showRoomURL(connection.sessionid);
  });
};

openOrJoinRoom = function() {
  console.log("joining room",roomid);
  connection.openOrJoin(roomid, function() {
     showRoomURL(connection.sessionid);
  });
};

connection.onstreamended = function(event) {
  var mediaElement = document.getElementById(event.streamid);
  if (mediaElement) {
    mediaElement.parentNode.removeChild(mediaElement);
  }
};

connection.onMediaError = function(e) {
  if (e.message === 'Concurrent mic process limit.') {
    if (DetectRTC.audioInputDevices.length <= 1) {
      alert('Please select external microphone. Check github issue number 483.');
      return;
    }

    var secondaryMic = DetectRTC.audioInputDevices[1].deviceId;
    connection.mediaConstraints.audio = {
      deviceId: secondaryMic
    };

    connection.join(connection.sessionid);
  }
};


function showRoomURL(roomid) {
  var roomHashURL = '#' + roomid;

  var html = 'room: <a href="' + roomHashURL + '" target="_blank">' + roomHashURL + '</a>';
  var roomURLsDiv = document.getElementById('room-urls');
  roomURLsDiv.innerHTML = html;

}

(function() {
  var params = {},
  r = /([^&=]+)=?([^&]*)/g;

  function d(s) {
    return decodeURIComponent(s.replace(/\+/g, ' '));
  }
   var match, search = window.location.search;
   while (match = r.exec(search.substring(1)))
   params[d(match[1])] = d(match[2]);
   window.params = params;
})();

// detect 2G
if(navigator.connection &&
   navigator.connection.type === 'cellular' &&
   navigator.connection.downlinkMax <= 0.115) {
    alert('2G is not supported. Please use a better internet service.');
}
