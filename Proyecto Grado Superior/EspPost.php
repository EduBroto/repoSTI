<?php

include'conexion.php';

if ($con) {
    echo "Conexion con base de datos exitosa! ";
    
    if(isset($_POST['temperatura'])) {
        $temperatura = $_POST['temperatura'];
        echo "Estación meteorológica";
        echo " Temperatura : ".$temperatura;
    }
 
    if(isset($_POST['humedad'])) { 
        $humedad = $_POST['humedad'];
        echo " Humedad : ".$humedad;
        date_default_timezone_set('Europe/Madrid');
        $fecha_actual = date("Y-m-d H:i:s");
        
        $consulta = "INSERT INTO TemperaturaHumedad(Temperatura,Humedad,fecha) VALUES ('$temperatura','$humedad', '$fecha_actual')";
       // $consulta = "UPDATE DHT11 SET Temperatura='$temperatura',Humedad='$humedad' WHERE Id = 1";
        $resultado = mysqli_query($con, $consulta);
        if ($resultado){
            echo " Registro dht11 en base de datos OK! ";
        } else {
            echo " Falla dht11! Registro BD";
        }
    }

    if(isset($_POST['temperatura2'])) {
        $temperatura2 = $_POST['temperatura2'];
        echo "Estación meteorológica";
        echo " Temperatura2 : ".$temperatura2;
    }
 
    if(isset($_POST['humedad2'])) { 
        $humedad2 = $_POST['humedad2'];
        echo " Humedad : ".$humedad2;
        date_default_timezone_set('Europe/Madrid');
        $fecha_actual = date("Y-m-d H:i:s");
        
        $consulta = "INSERT INTO TemperaturaHumedad2(Temperatura2,Humedad2,fecha) VALUES ('$temperatura2','$humedad2', '$fecha_actual')";
       // $consulta = "UPDATE DHT11 SET Temperatura='$temperatura',Humedad='$humedad' WHERE Id = 1";
        $resultado = mysqli_query($con, $consulta);
        if ($resultado){
            echo " Registro dht11 en base de datos OK! ";
        } else {
            echo " Falla dht11! Registro BD";
        }
    }
   
    /*if(isset($_POST['valldr'])) {
        $valldr = $_POST['valldr'];
        echo "Sensor lumínico";
        echo " Nivel de luz : ".$valldr;
        date_default_timezone_set('Europe/Madrid');
        $fecha_actual = date("Y-m-d H:i:s");

        $consulta = "INSERT INTO ValorLuz (ValorLux, fecha) VALUES ('$valldr','$fech_actual');
        $resultado = mysqli_query($con, $consulta);
        if ($resultado){
            echo " Regisrto ldr en base de datos OK! ";
        } else {
            echo " Falla ldr! Registro BD";
        }
    }
    
   

    */
    
} else {
    echo "Falla! conexion con Base de datos ";   
}


?>