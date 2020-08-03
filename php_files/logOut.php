<html>
<style>
    /* Add a black background color to the top navigation */
    .topnav {
      background-color: #000033;
      overflow: hidden;
    }
    
    /* Style the links inside the navigation bar */
    .topnav a {
      float: left;
      color: white;
      text-align: center;
      padding: 14px 16px;
      text-decoration: none;
      font-size: 17px;
    }
    
    /* Change the color of links on hover */
    .topnav a:hover {
      background-color: #9BC4E2;
      color: white;
    }
    
    /* Add a color to the active/current link */
    .topnav a:active {
      color: #3f000f;
      background-color: #4CAF50;
    }
</style>
<body style = "background-color: #FCFCFF">
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