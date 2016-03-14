#include <Python.h>
#include <pthread.h>
#include "aCync.h"

static PyObject *
aCync_read(PyObject *self, PyObject *args)
{
    int retval;
     retval = get_output_data();
    return PyLong_FromLong(retval);
}

static PyObject *
aCync_write(PyObject *self, PyObject *args)
{

}


static PyMethodDef aCyncMethods[] = {
    {"read",  aCync_read, METH_VARARGS,
     "Read data from the async buffer"},
	{"write", aCync_write, METH_VARARGS,
	 "Write data to the async buffer"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef aCyncmodule = {
   PyModuleDef_HEAD_INIT,
   "aCync",   /* name of module */
   NULL, /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   aCyncMethods
};

PyMODINIT_FUNC
PyInit_aCync(void)
{
	PyObject *module;

	module = PyModule_Create(&aCyncmodule);

	return module;
}
