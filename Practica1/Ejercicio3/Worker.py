import MySQLdb
import random
import time

#Conexion a la base de datos
connection = MySQLdb.connect("localhost", "root", "root", "test")

try:
    cur = connection.cursor()
    #Limpia la tabla de la base de datos
    sql = "DELETE FROM dato"
    cur.execute(sql)
    connection.commit()
    #Resetea los ID
    sql = "ALTER TABLE dato AUTO_INCREMENT = 1"
    cur.execute(sql)
    connection.commit()

    #Genera los valores aleatorios cada cierta cantidad de tiempo y los carga en la base de datos
    while True:
            #Genera los valores aleatorios
            Temperatura = random.randint(-10,35)
            Humedad = random.randint(0,100)
            Presion = random.randint(980,1020)
            Viento = random.randint(0,50)

            #Inserta los datos en la base de datos
            randomInsert = "INSERT INTO dato VALUES (null, %s, %s, %s, %s)"
            cur.execute(randomInsert, (Temperatura, Humedad, Presion, Viento))
            connection.commit()

            #Espera un tiempo determinado
            time.sleep(2)

finally:
    #Cierra la conexion
    connection.close()
