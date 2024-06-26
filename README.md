# cpp05
C++ - Module 05 Repetition and Exceptions

## ex00

- Implementar mensajes de error personalizados para el ejercicio utilizando la clase std:exception:

- Las excepciones son una forma de manejar errores y condiciones excepcionales en C++. En lugar de usar códigos de error, puedes lanzar y capturar excepciones, lo que hace que el código sea más claro y fácil de mantener

- Clase std::exception
	- La clase base para todas las excepciones estándar en C++ es std::exception. Esta clase proporciona una interfaz común para trabajar con excepciones. La función más importante de std::exception es:
		- virtual const char* what() const throw();
			- Devuelve un mensaje de error que describe la excepción.
				Puedes heredar de std::exception para crear tus propias clases de excepción personalizadas.

	- Crear Excepciones Personalizadas
- En el ejercicio, se crearon dos excepciones personalizadas: GradeTooHighException y GradeTooLowException. Ambas heredan de std::exception y sobrescriben el método what para proporcionar mensajes de error específicos.

```c++
class Bureaucrat::GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade is too high!";
    }
};

class Bureaucrat::GradeTooLowException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade is too low!";
    }
};
```

## ex01

- Añadir un formulario que solo pueda ser firmado si el burocrata tiene el nivel para firmarlo

```c++
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}
```
- si se cumple la condicion lanzaremos la excepcion;

## ex02

- Form ahora es Abstracto
- Tenemos 3 tipos de formularios que heredan de Form
- El metodo executeForm dentro de burocrata comprueba que se pueda firmar o y ejecutar
- Los execute de los distintos formularios pasan por la comprobacion de el metodo execute de el buroctrata

## ex03

- la clase intern se encarga de recibir el nombre del formulario y el target;

- Como no se puede if/elses anidados hice
un array a funciones

- Manejamos el error de que nos den un nombre de formulario erroneo con una excepcion