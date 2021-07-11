<html>
<body>
<h3>Enter information about a Team to add to the database:</h3>

<form action="odbc_Add_Team.php" method="post">

    University Name: <input type="text" name="University Name"><br>
    Nickname: <input type="text" name="Nickname"><br>
    Rank: <input type="number" name="Rank"><br>
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
    //$TeamId = escapeshellarg($_POST[TeamId]);
    $University_Name = escapeshellarg($_POST[University_Name]);
    $Nickname = escapeshellarg($_POST[Nickname]);
    $Rank= escapeshellarg($_POST[Rank]);

    $command = '/home/jrnolasc/public_html/project_cpp/odbc_Add_Team.exe  ' . $University_Name . ' ' . $Nickname . ' ' . $Rank;

    
    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 

    system($command);           
}
?>


