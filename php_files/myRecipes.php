<?php
    include("connector.php");
?>
<html>
<body style = "background-color: #F7F7F7">
</body>
</html>
 <?php
    $sql = "SELECT ID FROM currentUser";
    $res = mysqli_query($conn, $sql);
    while($row = mysqli_fetch_array($res)) $userID = $row['ID'];
    
    $recipeSQL = "SELECT * FROM `MyRecipe` WHERE UserID = \"$userID\"";
    //$recipeSQL = "SELECT * FROM Users";
    $recipes = mysqli_query($conn, $recipeSQL);
    
    //reccomended recipe table (only top 3 recipes)
    $recommendSQL = "CALL `RecommendRecipes`(\"$userID\");";
    $recommendedRecipes = mysqli_query($conn, $recommendSQL);
    
    echo "<h1> Recommended Recipes </h1>";
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
    
 
    echo "<h1> Favorite Recipes </h1>";
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