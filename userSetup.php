<html>
<body>

<?php

$userID = $_GET["UserID"];
$userName = $_GET["UserName"];

//connect to sql server
$servername = "web";
$username = "user";
$password = "P@ntry!!";
$dbname = 'PantryCS411';
$mysqli = new mysqli($servername,$username,$password, $dbname);

if($mysqli->connect_erro){
    echo "Failed to connect to MySQL: (" . $mysqli->connect_erro . ") " $mysqli->connect_error;
}
//inserting user
if (!$mysqli -> query("INSERT INTO Users(UserId, UserName) VALUES('$userID','$userName')"))
    echo "Welcome Back";

//connect pantry data to table
$pantry = "SELECT * FROM Pantry WHERE UserID = $userID"

//inserting into pantry
for ($x = 0; $x <=sizeof(pantry) ; $x++) {
        $sql = "INSERT INTO Pantry(UserID, Name, Quantity, Type, Expiration) VALUES ('$currentUser['userID']','$pantry[$x]['name']', '$pantry[$x]['quantity']', '$pantry[$x]['type']', '$pantry[$x]['expiration']')";
    }
}
//deleting from pantry
if (shouldDeleteItem) {
    $sql = "DELETE FROM Pantry WHERE UserID = '$deleteItem['userID']' AND Name = '$deleteItem['name']";
}
//updating from pantry
if (shoudlUpdateItem){
    $sql = "UPDATE Pantry SET Quantity = '$updateItem['quantity']' WHERE UserID = '$updateItem['userID']' AND Name = '$updateItem['name']";
}


//close sql server
$mysqli->close();
?>
</body>
</html>
