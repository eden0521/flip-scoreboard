<?php

	include("connect.php"); 	
	
	$link=Connection();

	$result=mysql_query("SELECT * FROM `tempLog` ORDER BY `timeStamp` DESC",$link);
?>

<html>
   <head>
      <title>Baseball Scoreboard</title>
      <link rel="Shortcut Icon" type="image/x-icon" href="http://obo.myds.me/favicon.ico" />
   </head>
   <meta http-equiv="refresh" content="5" > 
<body>
   <h1>Baseball Scoreboard
   <?php
$time = date ('Y-m-d H:i:s');
echo $time;
?>
   </h1>

   <table border="1" cellspacing="1" cellpadding="1">
		<tr>
			<td bgcolor="#FF9933">&nbsp;Timestamp&nbsp;</td>
			<td bgcolor="#66FFFF">&nbsp;LEFT : RIGHT&nbsp;</td>			
			<td bgcolor="#FFFF00">&nbsp;  STRIKE  &nbsp;</td>
			<td bgcolor="#00FF00">&nbsp;      BALL      &nbsp;</td>
			<td bgcolor="#FF0000">&nbsp;      OUT      &nbsp;</td>
			<td bgcolor="#FF77FF">&nbsp;      ROUND      &nbsp;</td>
		</tr>

      <?php 
      
		  if($result!==FALSE){
		     while($row = mysql_fetch_array($result)) {
		        printf("<tr><td> &nbsp;%s &nbsp;</td><td> &nbsp;%s : &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td></tr>", 
		           $row["timeStamp"], $row["leftt"], $row["rightt"], $row["strike"], $row["ball"], $row["outt"], $row["roud"]);
		     }
		     mysql_free_result($result);
		     mysql_close();
		  }
      ?>

   </table>
</body>
</html>
