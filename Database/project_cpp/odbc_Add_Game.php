<html>
<body>
<h3>Enter information about a Game to add to the database:</h3>

<form action="odbc_Add_Game.php" method="post">
   
    Rank1: <input type="number" name="Rank1"><br>
    Rank2: <input type="number" name="Rank2"><br>
    Location: <input type="text" name="Location"><br>
    Date: <input type="text" name="Date">(YYYY-MM-DD)<br>
    <input name="submit" type="submit" >
</form>
<br><br>
<div style="position: absolute; bottom: 0; right: 0; width: 100px; text-align:right;">
    <a href=" http://www.csce.uark.edu/~jrnolasc/project_cpp/hello.html">HOME</a>
</div>

</body>
</html>

<?php
if (isset($_POST['submit'])) 
{
    // replace ' ' with '\ ' in the strings so they are treated as single command line args

    
    $Rank1 = escapeshellarg($_POST[Rank1]);
    $Rank2 = escapeshellarg($_POST[Rank2]);
    $Location = escapeshellarg($_POST[Location]);
    $Date = escapeshellarg($_POST[Date]);

    $command = '/home/jrnolasc/public_html/project_cpp/odbc_Add_Game.exe ' . $Rank1 . ' ' . $Rank2. ' ' . $Location. ' ' . $Date;

   
    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 
    // run odbc_insert_item.exe
    system($command);           
}
?>


