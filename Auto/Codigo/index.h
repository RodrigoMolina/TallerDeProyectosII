
const char MAIN_page[] PROGMEM = R"=====(
<HTML>
	<HEAD>
			<TITLE>My first web page</TITLE>
	</HEAD>
<BODY>
	<CENTER>
		<B>Control</B>
		<form action="" method="get">
			<input type="hidden" name="Direccion" value="Derecha">
			<input type="submit" value="Derecha" />
		</form>
		<form action="" method="get">
			<input type="hidden" name="Direccion" value="Izquierda">
			<input type="submit" value="Izquierda" />
		</form>
		<form action="" method="get">
			<input type="hidden" name="Direccion" value="Avanzar">
			<input type="submit" value="Avanzar" />
		</form>
		<form action="" method="get">
			<input type="submit" value="Submit">
		</form>
	</CENTER>	
</BODY>
</HTML>
)=====";
