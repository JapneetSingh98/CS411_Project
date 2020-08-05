<?php
    session_start();
    include("connector.php");
?>
<html>
<body style = "background-color: #F7F7F7">
<head>
   <h1>
       Here you can add items to your pantry, delete items from pantry, or update already existing items.<br>
   </h1>
   <p> 
        To add an item, fill out all of the fields below and click on the Add button.<br>
        To update an item, fill out the name of the item you want to update, then fill in the corresponding fields you are updating.<br>
        To delete an item, fill out the name of the item you want to delete. <br>
   </p>
    <form action="" method="post">
      <label for="item">Item Name:</label>
      <input type="text" id="item" name="item"><br><br>
      <label for="Quantity">Qty:</label>
      <input type="text" id="Quantity" name="Quantity"><br><br>
      <label for="Type">Type of Measurement:</label>
      <input type="text" id="Type" name="Type"><br><br>
      <label for="Expiration">Expiration Date (YYYY-MM-DD):</label>
      <input type="text" id="Expiration" name="Expiration"><br><br>
      <input type="Submit" name="Add" value="Add Item"><br><br>
      <input type="Submit" name="Delete" value="Delete Item"><br><br>
      <input type="Submit" name="Update" value="Update Item"><br><br>
    </form>
</body>
</html>
<?php
    session_start();
    $item = $_POST["item"];
    $qty = $_POST["Quantity"];
    $type = $_POST["Type"];
    $date = $_POST["Expiration"];
    
    $stmt = $conn->prepare("SELECT ID FROM `currentUser` LIMIT 1");
    $stmt->execute();
    $result = $stmt->get_result();
    $userArr = $result->fetch_assoc();
    $userID = array_pop(array_reverse($userArr));
    
    if (isset($_POST['Add'])){
        $sql = "INSERT INTO `Pantry`(`UserID`, `Name`, `Quantity`, `Type`, `ExpirationDate`) VALUES (\"$userID\",\"$item\",\"$qty\",\"$type\",\"$date\")";
        $res = mysqli_query($conn, $sql);
    } else if (isset($_POST['Delete'])){
        $sql = "DELETE FROM Pantry WHERE UserID = '$userID' AND Name = '$item'";
        $res = mysqli_query($conn, $sql);
    } else if (isset($_POST['Update'])){
        $sql = "UPDATE Pantry SET Quantity = '$qty', Type = '$type', ExpirationDate = '$date' WHERE UserID = '$userID' AND Name = '$item'";
        $res = mysqli_query($conn, $sql);
    }

?>
