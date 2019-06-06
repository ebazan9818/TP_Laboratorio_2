
typedef struct
{
    int idSector;
    char description[51];
}eSector;

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int idSector;
    int isEmpty;

}eEmpleado;

/** \brief inicializa todos los campso en 0
 * \param vector:   vector de tipo estructura
 * \param tam:variable que indica el tamaño del vector.
 * \return void. */
void initEmployees(eEmpleado* vector, int tam);
/** \brief añade un nuevo empleado
 * \param vector: vector tipo estructura donde almacenaremos al nuevo empleado.
 * \param tam: tamaño del vector antes recibido.
 * \param array: vector de los sectores de la empresa
 * \param arrayTam: es el tamaño del vector de los sectores.
 * \return void. */
void addEmployee(eEmpleado* vector, int tam, eSector* array, int arrayTam);

/** \brief busca un espacio libre en el vector recibido para ingresar nueva variable
 * \param vector: es el vector tipo estructura con que el que trabaja la funcion.
 * \param tam: es el tamaño del vector antes recibido.
 * \return 0 si hay espacio libre, si no lo hay: -1. */
int espacioLibre(eEmpleado* vector, int tam);

/** \brief busca un empleado por id de legajo, para saber si existe en el sistema.
 * \param vector: es el vector tipo estructura a recorrer.
 * \param tam: tamaño del vector ingresado.
 * \param id: numero de legajo a buscar en el vector.
 * \return la ubicacon dele empleado, si vale -1 no existe ese empleado en el sistema.*/
int findEmployeeById(eEmpleado* vector, int tam,int id);

/** \brief da de baja un empleado.
 * \param vector:  vector con el que trabaja la funcion.
 * \param tam: tamaño del vector recibido.
 * \return void. */
int removeEmployee(eEmpleado* vector, int tam);

/** \brief Ordena la lista de empleados.
 * \param vector: vector con el que trabaja la funcion.
 * \param tam: tamaño del vector antes recibido.
 * \return void. */
void sortEmployees(eEmpleado* vector, int tam);

/** \brief lista todos los empleados.
 * \param vector: es el vector tipo estructura que contiene a todos los empleados activos.
 * \param tam: es el tamaño del array antes recibido.
 * \return void.
 */
void printEmployees(eEmpleado* vector, int tam);
/** \brief modifica los datos de un empleado.
 * \param vector de tipo estructura con el que trabaja la funcion.
 * \param tam: es el tamaño del vector antes recibido.
 * \return void. */
void modifyEmployee (eEmpleado* vector, int tam, eSector* array, int arrayTam);

/** \brief brinda un informe sobre el dinero que se invierte en salarios, el promedio y cuantos empleados superan dicho promedio.
 * \param vector de tipo estructura con el que trabaja la funcion.
 * \param tam: es el tamaño del vector antes recibido.
 * \return void. */
void informeSalarios(eEmpleado* vector, int tam);

