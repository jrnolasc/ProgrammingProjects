<html>
<body>
<h3>Enter game result information you would like to add to the database:</h3>

<form action="odbc_Add_Result.php" method="post"> 
    Game ID: <input type="number"name="GameId"><br>
    Team One ID: <input type="number" name="TeamOneId"><br>
    Team Two ID: <input type="number" name="TeamTwoId"><br>
    Score One: <input type="number" name="ScoreOne"><br>
    Score Two: <input type="number" name="ScoreTwo"><br>
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

    $GameId = escapeshellarg($_POST[GameId]);
    $TeamOneId = escapeshellarg($_POST[TeamOneId]);
    $TeamTwoId = escapeshellarg($_POST[TeamTwoId]);
    $ScoreOne = escapeshellarg($_POST[ScoreOne]);
    $ScoreTwo = escapeshellarg($_POST[ScoreTwo]);

    $command = '/home/jrnolasc/public_html/project_cpp/odbc_Add_Result.exe ' . $GameId .' '. $TeamOneId . ' ' . $TeamTwoId . ' ' . $ScoreOne . ' ' . $ScoreTwo;
    if ($command == "/home/jrnolasc/public_html/project_cpp/odbc_Add_Result.exe '' '' '' '' ''")
    {
        echo "No Game Found";
    }
    //echo '<p>' . 'command: ' . $command . '<p>';
    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 
    // run odbc_insert_item.exe
    system($command);           
}
?>