disease(maleria) :- symptom(fever) , symptom(headache) , symptom(nausea).
disease(covid) :- symptom(fever) , symptom(cough) , symptom(fatigue).

predict :-
    (disease(maleria) -> write('Possible Disease : Maleria'),nl;
    disease(covid) -> write('Covid'),nl;
    write('No matching disease'),nl).

ask(Symptom) :-
    format('Do you have ~w ?(yes/no)',[Symptom]),
    read(Response),
    (Response == yes -> assert(symptom(Symptom));
    Response == no -> true;
    write('Enter yes or no only') , nl , ask(Symptom)).

get :-
    retractall(symptoms(_)),
    ask(fever),
    ask(cough),
    ask(headache),
    ask(fatigue),
    ask(nausea).

start :-
    get,
    predict.