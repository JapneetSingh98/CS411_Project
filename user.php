<html>
<head>
    <link rel="stylesheet" type="text/css" href="navbar.css">
</head>
<body>
    <div class="topnav">
        <a class="home" href="/index.html">Home</a>
        <a href="/pantryUpdates.php"> Update Pantry</a>
        <a href="/searchRecipes.php">Search Recipes</a>
        <a href="/myRecipes.php">My Recipes</a>
   </div>
 </body>
 </html>
<?php
    $userID = $_GET["userID"];
    $password = $_GET["password"];
    //connect to sql server
    $servername = "localhost";
    $username = "pantrycs411_user";
    $pass = "P@ntry!!";
    $dbname = "pantrycs411_ver1";
    $conn = mysqli_connect($servername, $username, $pass, $dbname);
    if (!$conn) {
       echo "<h1>we not connected</h1>";
    }

    //insert user
    if(isset($_GET["signUp"])){
        $sql = "INSERT INTO Users (UserId, Password) VALUES('$userID', '$password');";
        mysqli_query($conn, $sql);
        if (mysqli_error($conn)) echo("UserID is already taken");
        else echo("Click on Home and log in with your username and password!");
    } else if(isset($_GET["login"])){
        $sql = "SELECT * FROM Users WHERE UserID = '$userID' AND Password = '$password'";
        $res = mysqli_query($conn, $sql);
        if (mysqli_num_rows($res)==0) echo("Incorrect username or password, please click on Home and try again");
        else {
            //echo("Below are your pantry items");
            
            $sql = "SELECT * FROM Pantry WHERE UserID = '$userID'";
            $res = mysqli_query($conn, $sql);
            
            echo "<table border='1'>
            <tr>
            <th>UserID</th>
            <th>Name</th>
            <th>Quantity</th>
            <th>Type</th>
            <th>Expiration Date</th>
            </tr>";
            while($row = mysqli_fetch_array($res))
            {
                echo "<tr>";
                echo "<td>" . $row['UserID'] . "</td>";
                echo "<td>" . $row['Name'] . "</td>";
                echo "<td>" . $row['Quantity'] . "</td>";
                echo "<td>" . $row['Type'] . "</td>";
                echo "<td>" . $row['ExpirationDate'] . "</td>";
                echo "</tr>";
            }
            echo "</table>";
        }
    }
    
?>

