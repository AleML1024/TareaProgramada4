#ifndef ExcepcionRespuestaInvalida_H
#define ExcepcionRespuestaInvalida_H

#include <exception>

class ExcepcionRespuestaInvalida : public std::exception
{
    public:
    ExcepcionRespuestaInvalida() noexcept = default;
    ~ExcepcionRespuestaInvalida() = default;

    virtual const char* what() const noexcept {
        return "Respuesta inválida, por favor responder con lo que se le solicita. \n";
    }

};

#endif