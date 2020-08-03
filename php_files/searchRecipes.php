<?php
    include_once("connector.php");
?>
<html>
<body>
    <form action="" method="post">
        <label for="Search">Search Recipes:</label>
        <input type="text" id=\"Search\" name="Search"><br><br>
        <input type="Submit" value="Search"><br><br>
    </form>
 </body>
 </html>
<?php
    $name = $_POST["Search"];
    
    $sql = "SELECT ID, Name FROM Recipe WHERE Name LIKE \"%" . $name . "%\"";
    $res = mysqli_query($conn, $sql);

    echo "<table border='1'>
    <tr>
    <th>ID</th>
    <th>Name</th>
    </tr>";
    echo "<form name=\"recipeDetails\" action=\"recipeDetails.php\" method=\"post\">";
    while($row = mysqli_fetch_array($res))
    {
        $id = $row['ID'];
        echo "<tr>";
        echo "<td><input type='Submit' name='Details' value='$id'></td>";
        echo "<td>" . $row['Name'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";

?>
