<html>
<body>

<!--<form action="pantryInserts.php" method="get">
  <label for="userID">userID:</label>
  <input type="text" id=\"userID\" name="userID"><br><br>
  <label for="item">Item Name:</label>
  <input type="text" id="item" name="item"><br><br>
  <label for="Quantity">Qty:</label>
  <input type="text" id="Quantity" name="Quantity"><br><br>
  <label for="Type">Type of Measurement:</label>
  <input type="text" id="Type" name="Type"><br><br>
  <label for="Expiration">Expiration Date:</label>
  <input type="text" id="Expiration" name="Expiration"><br><br>
  <input type="Submit" value="Add"><br><br>
</form> -->
//edit

<form action="pantryInserts.php" method="get">
  <label for="Search">Search Recipes:</label>
  <input type="text" id=\"Search\" name="Search"><br><br>
  <input type="Submit" value="Add"><br><br>
</form>

</body>
</html>

<?php
    session_start();

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
  }

  //insert user
  $sql = "INSERT INTO Users (UserId, UserName) VALUES('$userID', '$userName');";
  $res = mysqli_query($conn, $sql);


$sql = "SELECT * FROM Pantry";
$res = mysqli_query($conn, $sql);


/*echo "<table border='1'>
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
echo "</table>";*/


echo "<table border='1'>
<tr>
<th>ID</th>
<th>Name</th>
</tr>";

while($row = mysqli_fetch_array($res))
{
echo "<tr>";
echo "<td>" . $row['ID'] . "</td>";
echo "<td>" . $row['Name'] . "</td>";
echo "</tr>";
}
echo "</table>";

?>
