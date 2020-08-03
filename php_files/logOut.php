<html>
<head>
    <link rel="stylesheet" type="text/css" href="navbar.css">
</head>
<body>
    <div class="topnav">
        <a class="home" href="/index.html">Home</a>
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
    
    $sql = "SELECT ID FROM currentUser";
    $res = mysqli_query($conn, $sql);
    while($row = mysqli_fetch_array($res))
    {
        $id = $row['ID'];
        $sql = "DELETE FROM currentUser WHERE ID = '$id'";
        $res = mysqli_query($conn, $sql);
        echo "<h1> You have sucessfully logged out </h1>";
    }
    
    
?>