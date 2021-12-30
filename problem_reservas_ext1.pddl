(define (problem asignar-reservas-ext1)
  (:domain reservas-ext1)
  (:objects
    D1 D2 D3 D4 D5 D6 D7 D8 D9 D10 D11 D12 D13 D14 D15 D16 D17 D18 D19 D20 D21 D22 D23 D24 D25 D26 D27 D28 D29 D30 - dia
    H1 - habitacion
    R1 R2 R3 - reserva
  )
  (:init
    (= (que-dia D1) 1)
    (= (que-dia D2) 2)
    (= (que-dia D3) 3)
    (= (que-dia D4) 4)
    (= (que-dia D5) 5)
    (= (que-dia D6) 6)
    (= (que-dia D7) 7)
    (= (que-dia D8) 8)
    (= (que-dia D9) 9)
    (= (que-dia D10) 10)
    (= (que-dia D11) 11)
    (= (que-dia D12) 12)
    (= (que-dia D13) 13)
    (= (que-dia D14) 14)
    (= (que-dia D15) 15)
    (= (que-dia D16) 16)
    (= (que-dia D17) 17)
    (= (que-dia D18) 18)
    (= (que-dia D19) 19)
    (= (que-dia D20) 20)
    (= (que-dia D21) 21)
    (= (que-dia D22) 22)
    (= (que-dia D23) 23)
    (= (que-dia D24) 24)
    (= (que-dia D25) 25)
    (= (que-dia D26) 26)
    (= (que-dia D27) 27)
    (= (que-dia D28) 28)
    (= (que-dia D29) 29)
    (= (que-dia D30) 30)

    (= (num-personas-hab H1) 3)
    (= (num-personas-res R1) 3)
    (= (num-personas-res R2) 3)
    (= (num-personas-res R3) 3)
    (= (dia-inicial R1) 1) 
    (= (dia-final R1) 15) 
    (= (dia-inicial R2) 16) 
    (= (dia-final R2) 29) 
    (= (dia-inicial R3) 29) 
    (= (dia-final R3) 30) 

    (= (num-reservas-asig) 0)
  )
  (:goal
    (forall
      (?r - reserva) 
      (or
        (reserva-asignada ?r)
        (not 
          (exists 
            (?h - habitacion)
            (and
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
          )
        )
      )
    )
  )
  (:metric maximize 
    (num-reservas-asig)
  )
)