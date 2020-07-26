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
    <form action="" method="get">
        <label for="Search">Search Recipes:</label>
        <input type="text" id=\"Search\" name="Search"><br><br>
        <input type="Submit" value="Add"><br><br>
    </form>
 </body>
 </html>
<?php
    session_start();
    $name = $_GET["Search"];
 
    //connect to sql server
    $servername = "localhost";
    $username = "pantrycs411_user";
    $pass = "P@ntry!!";
    $dbname = "pantrycs411_ver1";
    $conn = mysqli_connect($servername, $username, $pass, $dbname);
    if (!$conn) {
        echo "<h1>we not connected</h1>";
    }


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

?>
