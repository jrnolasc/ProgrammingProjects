<html>
<body>
<h3>Enter the date you would like to view the results for:</h3>

<form action="odbc_View_Date_Results.php" method="post">
    Date: <input type="text" name="Dates">(YYYY-MM-DD)<br>
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

    $Dates = escapeshellarg($_POST[Dates]);

    $command = '/home/jrnolasc/public_html/project_cpp/odbc_View_Date_Results.exe ' . $Dates;

   
    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 
    // run odbc_insert_item.exe
    system($command);           
}
?>