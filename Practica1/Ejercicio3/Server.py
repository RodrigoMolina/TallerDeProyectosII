import MySQLdb
from flask import Flask
from flask import render_template
from flask import request

app = Flask(__name__)
app.config['TEMPLATES_AUTO_RELOAD'] = True



connection = MySQLdb.connect("localhost", "root", "root", "test")
def get_data():
    return promedio

@app.route('/', methods=['GET'])
def index():
    promedio = [0, 0, 0, 0]
    ultimaMuestra = [0, 0, 0, 0]
    primero = True

    try:
        #Realiza la coneccion a la base de datos
        c = connection.cursor()
        #Obtiene los ultimos 10 valores de muestra de la base de datos en orden invertido
        sql = "SELECT * FROM dato ORDER BY ID DESC LIMIT 10"
        c.execute(sql)
        connection.commit()
        rows = c.fetchall()

        #Recorre las 10 lineas sumandolas en la lista promedio y guardando la primera linea
        #en la lista ultimaMuestra que es el ultimo valor muestreado
        for row in rows:
            if(primero):
                ultimaMuestra[0] = row[1]
                ultimaMuestra[1] = row[2]
                ultimaMuestra[2] = row[3]
                ultimaMuestra[3] = row[4]
                primero = False
            promedio[0] += row[1]
            promedio[1] += row[2]
            promedio[2] += row[3]
            promedio[3] += row[4]
    finally:
        c.close();

    #Divide por 10 para sacar el promedio
    promedio[0] /= 10
    promedio[1] /= 10
    promedio[2] /= 10
    promedio[3] /= 10
    #Devuelve el html donde se veran los datos, y pasa por get los datos a mostrar
    return render_template('index.html', p = promedio, u = ultimaMuestra)

#Inicia el servidor web
if __name__ == "__main__":
    app.run(host='localhost', port=80)
