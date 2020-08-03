<html>
<head>
    <link rel="stylesheet" type="text/css" href="navbar.css">
</head>
<body>
    <div class="topnav">
        <a class="home" href="/index.html">Home</a>
        <a href="/myPantry.php"> My Pantry</a>
        <a href="/pantryUpdates.php"> Update Pantry</a>
        <a href="/searchRecipes.php">Search Recipes</a>
        <a href="/myRecipes.php">My Recipes</a>
        <a href="/logOut.php">Log Out</a>
   </div>
 </body>
 </html>
<?php
    session_start();
    //connect to sql server
    $servername = "localhost";
    $username = "pantrycs411_user";
    $pass = "P@ntry!!";
    $dbname = "pantrycs411_ver1";
    $conn = mysqli_connect($servername, $username, $pass, $dbname);
    if (!$conn) {
       echo "<h1>not connected</h1>";
    }
?>