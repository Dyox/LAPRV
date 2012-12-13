%user_profile(Id,Tags,DataNasc,Tel,Email,Linkedin,Facebook,Estado).
user_profile(nick_98,[sw,porto,masculino,pintor],_,_,_,_,_,_).
user_profile(killabeep,[trance,porto],_,_,_,_,_,_).
user_profile(fred,[lx,lisboa,'nu metal'],_,_,_,_,_,_).
user_profile(mariposa,[mala,apple,arte,pintura],_,_,_,_,_,_).
user_profile(quimera,[pintor,barroco,'neo classico'],_,_,_,_,_,_).
user_profile(ana_gt,[musica,video],_,_,_,_,_,_).

%user_conn(Id,ConnList).
%ConnList=[(UserIdA,TagA,Strength1),(UserIdB,TagB,Strength2),...]
user_conn(killabeep,[(nick_98,irmao,3),(a,_,_),(b,_,_),(c,_,_)]).
user_conn(nick_98,[(killabeep,irmao,3),(fred,_,_),(mariposa,namorada,2),(quimera,_,_),(ana_gt,_,_)]).
user_conn(fred,[(nick_98,_,_),(d,_,_)]).
user_conn(mariposa,[(nick_98,namorada,2),(e,_,_),(f,_,_),(g,_,_),(quimera,_,_)]).
user_conn(quimera,[(nick_98,_,_),(mariposa,_,_),(h,_,_),(i,_,_),(j,_,_)]).
user_conn(ana_gt,[(l,_,_),(m,_,_),(n,_,_),(o,_,_),(nick_98,_,_)]).