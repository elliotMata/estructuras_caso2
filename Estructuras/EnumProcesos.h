/*Estos son los procesos por los que va a pasar la construccion de la casa, son los que van a ser insertados en la cola de procesos para llevar el control de en que situacion se encuentra*/

enum Proceso
{
    Permisos,
    Excavacion,
    Cimientos,
    Framing,
    Roofing,
    PlomeriaCableado,
    RevestimientoAislantes,
    Acabados
};