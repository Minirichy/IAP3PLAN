(define (domain reservas)
  (:requirements :strips :typing :adl :equality :fluents)
  (:types
    dia reserva habitacion orientacion - object
  )
  (:functions
    (que-dia ?d - dia)
    (num-personas-hab ?h - habitacion)
    
    (dia-inicial ?r - reserva)
    (dia-final ?r - reserva)
    (num-personas-res ?r - reserva)
    
    (reservas-no-asig)
    (plazas-no-asig)
    (reservas-orientacion-incorrecta)
  )
  (:predicates
    (dia-ocupado ?d - dia ?h - habitacion)
    (orientacion-hab ?h - habitacion ?o - orientacion)
    (orientacion-res ?r - reserva ?o - orientacion)
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
              (increase (plazas-no-asig) (- (num-personas-hab ?h) (num-personas-res ?r)))
              (when 
              	(not 
              		(exists (?o - orientacion) 
              			(and (orientacion-hab ?h ?o) (orientacion-res ?r ?o))
              		)
              	)
              	(increase (reservas-orientacion-incorrecta) 1)
              )
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