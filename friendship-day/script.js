// script.js
document.getElementById('happyButton').addEventListener('click', function() {
    window.location.href = "upi://pay?pa=minibarsnathsaikia-1@oksbi&pn=Dhritimn%20Saikia&am=50&cu=INR"
});

// Change background color on hover over the container
document.querySelector('.container').addEventListener('mouseover', function() {
    document.body.style.backgroundColor = "#e6e6fa";
});

document.querySelector('.container').addEventListener('mouseout', function() {
    document.body.style.backgroundColor = "#f0f8ff";
});
