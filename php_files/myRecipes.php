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
    
    //reccomended recipe table (only top 3 recipes)
    $recommendSQL = "CALL `RecommendRecipes`(\"$userID\");";
    $recommendedRecipes = mysqli_query($conn, $recommendSQL);
    echo "<table border='1'>
    <tr>
    <th>ID</th>
    <th>Name</th>
    </tr>";
    echo "<form name=\"RecipeDetails\" action=\"recipeDetails.php\" method=\"post\">";
    while($row = mysqli_fetch_array($recommendedRecipes))
    {
        $id = $row['RecipeID'];
        echo "<tr>";
        echo "<td><input type='Submit' name='Details' value='$id'></td>";
        echo "<td>" . $row['RecipeName'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    
    //My Recipe table
    $recipeSQL = "SELECT * FROM `MyRecipe` WHERE UserID = \"$userID\"";
    $recipes = mysqli_query($conn, $recipeSQL);
    echo "<table border='1'>
    <tr>
    <th>ID</th>
    <th>Name</th>
    </tr>";
    echo "<form name=\"RecipeDetails\" action=\"recipeDetails.php\" method=\"post\">";
    while($row = mysqli_fetch_array($recipes))
    {
        $id = $row['RecipeID'];
        echo "<tr>";
        echo "<td><input type='Submit' name='Details' value='$id'></td>";
        echo "<td>" . $row['Name'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
 ?>