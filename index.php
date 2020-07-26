<html>
<body>

<?php

$userID = $_GET["UserID"];
$userName = $_GET["UserName"];
$
//connect to sql server
$servername = "localhost"; 
$username = "pantrycs411_user"; 
$pass = "P@ntry!!"; 
$dbname = "pantrycs411_ver1";  
$conn = mysqli_connect($servername, $username, $pass, $dbname);  
if (!$conn) { 
  echo "<h1>we not connected</h1>";
}
//inserting user
if (!$mysqli -> query("INSERT INTO Users(UserId, UserName) VALUES('$userID','$userName')"))
    echo "Welcome Back";

// //connect pantry data to table
// $pantry = "SELECT * FROM Pantry WHERE UserID = $userID"
// $num_rows = $pantry->num_rows;
// if ($num_rows>0){
//   print("<p>" . $num_rows . " results(s) found.</p>");
//   while ($row = $pantry->fetch_assoc()) {}
// }
//
// //inserting into pantry
// for ($x = 0; $x <=sizeof(pantry) ; $x++) {
//         $sql = "INSERT INTO Pantry(UserID, Name, Quantity, Type, Expiration) VALUES ('$currentUser['userID']','$pantry[$x]['name']', '$pantry[$x]['quantity']', '$pantry[$x]['type']', '$pantry[$x]['expiration']')";
//     }
// }
// //deleting from pantry
// if (shouldDeleteItem) {
//     $sql = "DELETE FROM Pantry WHERE UserID = '$deleteItem['userID']' AND Name = '$deleteItem['name']";
// }
// //updating from pantry
// if (shoudlUpdateItem){
//     $sql = "UPDATE Pantry SET Quantity = '$updateItem['quantity']' WHERE UserID = '$updateItem['userID']' AND Name = '$updateItem['name']";
// }


//close sql server
$mysqli->close();
?>
</body>
</html>
