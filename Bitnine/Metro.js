function initMap() {
    const map = new google.maps.Map(document.getElementById("map"), {
            zoom: 11,
            center: { lat: 34.0522, lng: -118.2437 },

});

const transitLayer = new google.maps.TransitLayer();

transitLayer.setMap(map);
}

window.initMap = initMap;