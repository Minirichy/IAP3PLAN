(define (domain reservas-ext3)
  (:requirements :typing :fluents)
  (:types
    dia
    reserva
    habitacion
  )
  (:functions
    (que-dia ?d - dia)
    (num-personas-hab ?h - habitacion)
    
    (dia-inicial ?r - reserva)
    (dia-final ?r - reserva)
    (num-personas-res ?r - reserva)
    
    (num-reservas-asig)
    (places-assignades)
  )
  (:predicates
    (dia-ocupado ?d - dia ?h - habitacion)
    (reserva-asignada ?r - reserva)
  )
  (:action assign-hab
    :parameters (?h - habitacion ?r - reserva)
    :precondition (and
                    (>= (num-personas-hab ?h) (num-personas-res ?r)) 
                    (forall (?d - dia) 
                      (or
                        (not (dia-ocupado ?d ?h))
                        (or 
                          (< (que-dia ?d) (dia-inicial ?r)) 
                          (< (dia-final ?r) (que-dia ?d))
                        )
                      )
                    )
                  )
    :effect (and
              (increase (num-reservas-asig) (num-personas-res ?r))
              (reserva-asignada ?r)
              (forall (?d - dia)
                (when
                  (and 
                    (<= (dia-inicial ?r) (que-dia ?d))
                    (<= (que-dia ?d) (dia-final ?r))
                  )
                  (dia-ocupado ?d ?h)
                )
              )
            )
  )
)