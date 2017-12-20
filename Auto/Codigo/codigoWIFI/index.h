
const char MAIN_page[] PROGMEM = R"=====(
<HTML>
	<HEAD>
			<TITLE>CarCar</TITLE>
	</HEAD>
<BODY style="background-color:green">
     
	<CENTER>
		<H1 style="font-size:80px">CarCar</H1>

<table style="width:50%">
  <tr>
    <th></th>
    <th></th> 
    <th>
		<form action="" method="get">
			<input type="hidden" name="Data"  value="N">
			<input type="submit" style="width:180px;height:60px;font-size: 200%;" value="PARAR" />
		</form></th>
  </tr>
  <tr>
    <td>
		<form action="" method="get">
			<input type="hidden" name="Data"  value="A">
			<input type="submit" style="width:180px;height:60px;font-size: 370%;" value="^" />
		</form>
	</td>
    <td></td> 
    <td></td>
  </tr>
  <tr>
    <td>
		<form action="" method="get">
			<input type="hidden" name="Data"  value="R">
			<input type="submit" style="width:180px;height:60px;font-size: 300%;" value="v" />
		</form>
	</td>
    <td>
		
	</td> 
    <td></td>
  </tr>
   <tr>
    <td></td>
    <td></td>
    <th>
		<form action="" method="get">
			<input type="hidden" name="Data" value="I">
			<input type="submit" style="width:180px;height:60px;font-size: 300%;" value="<" />
		</form>
	</th> 
    <th>
		<form action="" method="get">
			<input type="hidden" name="Data" value="D">
			<input type="submit" style="width:180px;height:60px;font-size: 300%;" value=">" />
		</form>
	</th>
    <td></td>
    <th></th>
    <td></td>
  </tr>
</table>
</CENTER>	
</BODY>
</HTML>
)=====";
