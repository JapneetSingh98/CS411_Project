<?php
    include_once("connector.php");
?>
<html>
<body>
</body>
</html>
 <?php
    $sql = "SELECT ID FROM currentUser";
    $res = mysqli_query($conn, $sql);
    while($row = mysqli_fetch_array($res)) $userID = $row['ID'];
    
    $sql = "SELECT RecipeID, Name FROM MyRecipe WHERE UserID = '$userID'";
    $res = mysqli_query($conn, $sql);

    echo "<table border='1'>
    <tr>
    <th>ID</th>
    <th>Name</th>
    </tr>";
    echo "<form name=\"RecipeDetails\" action=\"recipeDetails.php\" method=\"post\">";
    while($row = mysqli_fetch_array($res))
    {
        $id = $row['RecipeID'];
        echo "<tr>";
        echo "<td><input type='Submit' name='Details' value='$id'></td>";
        echo "<td>" . $row['Name'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
 ?>