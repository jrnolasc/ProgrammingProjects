<html>
<body>
<h3>Enter information about a restaurant to add to the database:</h3>

<form action="odbc_insert_item.php" method="post">
    Name: <input type="text" name="name"><br>
    Price_Per_LB: <input type="text" name="price_per_lb"><br>
    Roasting: <input type="text" name="roasting"><br>
    <input name="submit" type="submit" >
</form>
<br><br>

</body>
</html>

<?php
if (isset($_POST['submit'])) 
{
    // replace ' ' with '\ ' in the strings so they are treated as single command line args
    $name = escapeshellarg($_POST[name]);
    $price_per_lb = escapeshellarg($_POST[price_per_lb]);
    $roasting= escapeshellarg($_POST[roasting]);

    $command = '/home/jrnolasc/public_html/project_cpp/odbc_insert_item.exe ' . $name . ' ' . $price_per_lb . ' ' . $roasting;

    echo '<p>' . 'command: ' . $command . '<p>';
    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 
    // run odbc_insert_item.exe
    system($command);           
}
?>


