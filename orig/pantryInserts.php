<html>
<body>


</body>
</html>
<?php
    session_start();
    //include "index1.php";
//hello
   $name = $_GET["Search"];
 /* $id = $_GET["userID"];
  $item = $_GET["item"];
  $qty = $_GET["Quantity"];
  $type = $_GET["Type"];
  $date = $_GET["Expiration"]; */

   //connect to sql server
  $servername = "localhost";
  $username = "pantrycs411_user";
  $pass = "P@ntry!!";
  $dbname = "pantrycs411_ver1";
  $conn = mysqli_connect($servername, $username, $pass, $dbname);
  if (!$conn) {
    echo "<h1>we not connected</h1>";
  }


 // $sql = "INSERT INTO Pantry (UserID, Item, Quantity, Type, ExpirationDate) VALUES(" . $id . ","  . $item . "," . $qty . "," . $type . "," . $date . ");";

  $sql = "SELECT ID, Name FROM Recipe WHERE Name LIKE \"%" . $name . "%\"";
  $res = mysqli_query($conn, $sql);

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



 //header('Location: index1.php');

?>
