(define (domain reservas-ext1)
  (:requirements :strips :typing :adl :equality :fluents)
  (:types
    dia reserva habitacion - object
  )
  (:functions
    (que-dia ?d - dia)
    (num-personas-hab ?h - habitacion)
    
    (dia-inicial ?r - reserva)
    (dia-final ?r - reserva)
    (num-personas-res ?r - reserva)
    
    (reservas-no-asig)
  )
  (:predicates
    (dia-ocupado ?d - dia ?h - habitacion)
    (reserva-asignada ?r - reserva)
    (reserva-no-asignada ?r - reserva)
  )
  (:action assign-hab
    :parameters (?h - habitacion ?r - reserva)
    :precondition (and
                    (>= (num-personas-hab ?h) (num-personas-res ?r)) 
                    (not (reserva-asignada ?r))
                    (not (reserva-no-asignada ?r))
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
  (:action no-assignar-res
      :parameters (?r - reserva)
      :precondition (and (not (reserva-asignada ?r)) (not (reserva-no-asignada ?r)))
      :effect (and 
        (increase (reservas-no-asig) 1)
        (reserva-no-asignada ?r)  
      )
  )
)