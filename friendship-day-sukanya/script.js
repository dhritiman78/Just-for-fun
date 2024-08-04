// script.js
document.getElementById('happyButton').addEventListener('click', function() {
    window.location.href = "upi://pay?pa=sukanyadeori02@okaxis&pn=Sukanya%20Deori&am=100&cu=INR"
});

// Change background color on hover over the container
document.querySelector('.container').addEventListener('mouseover', function() {
    document.body.style.backgroundColor = "#e6e6fa";
});

document.querySelector('.container').addEventListener('mouseout', function() {
    document.body.style.backgroundColor = "#f0f8ff";
});
