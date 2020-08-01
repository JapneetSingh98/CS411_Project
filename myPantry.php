<html>
<body>
    
    
</body>   
</html>

<?php
    include "connector.php";
    $sql = "SELECT ID FROM currentUser";
    $res = mysqli_query($conn, $sql);
    while($row = mysqli_fetch_array($res)) $userID = $row['ID'];
        
    $sql = "SELECT * FROM Pantry WHERE UserID = '$userID'";
    $res = mysqli_query($conn, $sql);
    
    echo "<table border='1'>
    <tr>
    <th>UserID</th>
    <th>Name</th>
    <th>Quantity</th>
    <th>Type</th>
    <th>Expiration Date</th>
    </tr>";
    while($row = mysqli_fetch_array($res))
    {
        echo "<tr>";
        echo "<td>" . $row['UserID'] . "</td>";
        echo "<td>" . $row['Name'] . "</td>";
        echo "<td>" . $row['Quantity'] . "</td>";
        echo "<td>" . $row['Type'] . "</td>";
        echo "<td>" . $row['ExpirationDate'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
?>