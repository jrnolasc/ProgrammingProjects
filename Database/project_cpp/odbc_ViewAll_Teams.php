<html>
<body>
<h3>All Teams:</h3>

<form action="odbc_ViewAll_Teams.php" method="post">
</form>
<br><br>
<div style="position: absolute; bottom: 0; right: 0; width: 100px; text-align:right;">
    <a href=" http://www.csce.uark.edu/~jrnolasc/project_cpp/hello.html">HOME</a>
</div>
</body>
</html>

<?php

    

    $command = '/home/jrnolasc/public_html/project_cpp/odbc_ViewAll_Teams.exe ';

    //echo '<p>' . 'command: ' . $command . '<p>';
    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 
    // run odbc_insert_item.exe
    system($command);           

?>


