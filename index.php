<html>
<head>
    <link rel="stylesheet" type="text/css" href="navbar.css">
</head>
<body>
    <div class="topnav">
        <a class="home" href="#home">Home</a>
         <a href="/pantryInserts.php">Insert to Pantry</a>
           <a href="/searchRecipes.php">Search Recipes</a>
           <a href="/myRecipes.php">My Recipes</a>
   </div>
        <form action="user.php" method="get">
             <label for="userID">UserID:</label>
             <input type="text" id="userID" name="userID"><br><br>
             <label for="UserName">Username:</label>
             <input type="text" id="UserName" name="UserName"><br><br>
             <input type="Submit" value="Log in"><br><br>
        </form>


</body>
</html>

<?php
    $userID = $_GET["userID"];
    $userName = $_GET["UserName"];
    //connect to sql server
    $servername = "localhost";
    $username = "pantrycs411_user";
    $pass = "P@ntry!!";
    $dbname = "pantrycs411_ver1";
    $conn = mysqli_connect($servername, $username, $pass, $dbname);
    if (!$conn) {
       echo "<h1>we not connected</h1>";
    } else echo("hello");

    //insert user
    $sql = "INSERT INTO Users (UserId, UserName) VALUES('$userID', '$userName');";
    mysqli_query($conn, $sql);
    $pantry = "SELECT * FROM Pantry"
    $res = mysqli_query($conn, $pantry);
    

    echo "<table border='1'>
    <tr>
    <th>UserID</th>
    <th>Item</th>
    <th>Quantity</th>
    <th>Type</th>
    <th>ExpirationDate</th>
    </tr>";

    while($row = mysqli_fetch_array($res))
    {
        echo "<tr>";
        echo "<td>" . $row['UserID'] . "</td>";
        echo "<td>" . $row['Item'] . "</td>";
        echo "<td>" . $row['Quantity'] . "</td>";
        echo "<td>" . $row['Type'] . "</td>";
        echo "<td>" . $row['ExpirationDate'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";

    header('Location: /index.html');
?>


