Examples for the fp package.
============================

Example of \\FParcsin, \\FParccos, \\FParcsincos
------------------------------------------------

::: {.container .ltx-source}
    \def\tsc#1#2#3{%Test and example of \FParcsin, \FParccos, \FParcsincos    
    \FParcsin\fps{#1} \testeq\fps{#2}% test that asin(#1)=#2
    \FParccos\fpc{#1} \testeq\fpc{#3}% test that acos(#1)=#3
    \FParcsincos\fpc\fps{#1} \testeq\fps{#3}\testeq\fpc{#2}% test \FParcsincos
    }

    \tsc{-1.}{-1.570796326794896619}{3.141592653589793238}
    \tsc{-.9}  {-1.1197695149986342} {2.690565841793530819}
    \tsc{-.901}{-1.12206913379314448} {2.692865460588041099}
    \tsc{-.8}   {-0.92729521800161225} {2.498091544796508869}
    \tsc{-.8001}{-0.927461903191685794}{2.498258229986582413}
    \tsc{-.7}    {-0.775397496610753039}{2.346193823405649658}
    \tsc{-.70001}{-0.775411499507692744}{2.346207826302589363}
    \tsc{-.6}     {-0.643501108793284369}{2.214297435588180988}
    \tsc{-.600001}{-0.643502358793870307}{2.214298685588766926}
    \tsc{-.5}      {-0.523598775598298861}{2.09439510239319548}
    \tsc{-.5000001}{-0.523598891068356546}{2.094395217863253165}
    \tsc{-.4}       {-0.41151684606748801} {1.982313172862384629}
    \tsc{-.40000001}{-0.411516856978382544}{1.982313183773279163}
    \tsc{-.3}        {-0.304692654015397501}{1.87548898081029412}
    \tsc{-.300000001}{-0.304692655063682339}{1.875488981858578958}
    \tsc{-.2}          {-0.201357920790330786}{1.772154247585227405}
    \tsc{-.20000000001}{-0.201357920800536993}{1.772154247595433612}
    \tsc{-.1}            {-0.100167421161559793}{1.670963747956456412}
    \tsc{-.1000000000001}{-0.100167421161660296}{1.670963747956556915}
    \tsc{0.}{0.}{1.570796326794896619}
    \tsc{0.1}             {0.100167421161559793}{1.470628905633336826}
    \tsc{0.10000000000001}{0.100167421161569843}{1.470628905633326776}
    \tsc{0.2}              {0.201357920790330786}{1.369438406004565833}
    \tsc{0.200000000000001}{0.201357920790331806}{1.369438406004564813}
    \tsc{0.3}               {0.304692654015397501}{1.266103672779499118}
    \tsc{0.3000000000000001}{0.304692654015397605}{1.266103672779499014}
    \tsc{0.4}                {0.41151684606748801} {1.159279480727408609}
    \tsc{0.40000000000000001}{0.411516846067488021}{1.159279480727408598}
    \tsc{0.5}                 {0.523598775598298861}{1.047197551196597758}
    \tsc{0.500000000000000001}{0.523598775598298862}{1.047197551196597757}
    \tsc{0.6}                 {0.643501108793284369}{0.92729521800161225}
    \tsc{0.600000000000000006}{0.643501108793284376}{0.927295218001612243}
    \tsc{0.7}                 {0.775397496610753039}{0.79539883018414358}
    \tsc{0.700000000000000007}{0.775397496610753049}{0.79539883018414357}
    \tsc{0.8}                 {0.92729521800161225} {0.643501108793284369}
    \tsc{0.800000000000000008}{0.927295218001612263}{0.643501108793284356}
    \tsc{0.9}                 {1.1197695149986342}  {0.451026811796262419}
    \tsc{0.900000000000000009}{1.119769514998634221}{0.451026811796262398}
    \tsc{1.}{1.570796326794896619}{0.}
:::

Example of \\FPartan, \\FParccot, \\FParctancot
-----------------------------------------------

::: {.container .ltx-source}
    \def\tsc#1#2#3{%Test and example of \FParctan, \FParccot, \FParctancot 
    \FParctan\fps{#1} \testeq\fps{#2}% test that atan(#1)=#2
    \FParccot\fpc{#1} \testeq\fpc{#3}% test that acot(#1)=#3
    \FParctancot\fpc\fps{#1}\testeq\fps{#3}\testeq\fpc{#2}% test \FParctancot
    }

    \tsc{0.889}{0.726704406222857453}{0.844091920572039166}
    \tsc{0.890}{0.727262687996690304}{0.843533638798206315}
    \tsc{0.892}{0.728377589311900894}{0.842418737482995725}
    \tsc{0.894}{0.729490277509065194}{0.841306049285831425}
    \tsc{0.898}{0.731709029900430245}{0.839087296894466374}
    \tsc{0.906}{0.736120146489240496}{0.834676180305656123}
    \tsc{0.922}{0.744837694424903254}{0.825958632369993365}
    \tsc{0.954}{0.761861057414458448}{0.808935269380438171}
    \tsc{0.985}{0.777841632166671506}{0.792954694628225113}
    \tsc{0.992}{0.781382120731606315}{0.789414206063290304}
    \tsc{0.997}{0.783895911147454389}{0.78690041564744223} 

    \tsc{0.}{0.}{1.570796326794896619}
    \tsc{0.1}{0.099668652491162029}{1.47112767430373459}
    \tsc{0.22}{0.216550304976089278}{1.354246021818807341}
    \tsc{0.333}{0.321450524402644595}{1.249345802392252024}
    \tsc{0.4444}{0.418187215564994362}{1.152609111229902257}
    \tsc{0.55555}{0.507094259099305631}{1.063702067695590988}
    \tsc{0.666666}{0.588002142008964001}{0.982794184785932618}
    \tsc{0.7777777}{0.661043120389146583}{0.909753206405750036}
    \tsc{0.88888888}{0.726642335716208364}{0.844153991078688255}
    \tsc{0.999999999}{0.785398162897448356}{0.785398163897448263}
    \tsc{1.}{0.78539816339744831}{0.785398163397448309}
    \tsc{1.2345678901}{0.88998749346786801}{0.680808833327028609}
    \tsc{2.23456789011}{1.150011837102468973}{0.420784489692427646}
    \tsc{4.23456789012}{1.338893311505790293}{0.231903015289106326}
    \tsc{8.2345678901134}{1.449948794166153296}{0.120847532628743323}
    \tsc{16.234567890113456}{1.50927709513268111}{0.061519231662215509}
    \tsc{32.23456789011345678}{1.53978367639978028}{0.031012650395116339}
    \tsc{64.234567890113456789}{1.555229642723458197}{0.015566684071438422}
    \tsc{100.234567890113456789}{1.560820059669425338}{0.009976267125471281}
    \tsc{1000.234567890113456789}{1.569796561640876217}{0.000999765154020402}
    \tsc{10000.234567890113456789}{1.570696329140853809}{0.00009999765404281}
    \tsc{100000.234567890113456789}{1.570786326818353686}{0.000009999976542933}
    \tsc{1000000.234567890113456789}{1.570795326795131187}{0.000000999999765432}
    \tsc{10000000.234567890113456789}{1.570796226794898965}{0.000000099999997654}
    \tsc{100000000.234567890113456789}{1.570796316794896643}{0.000000009999999976}
    \tsc{1000000000.234567890113456789}{1.57079632579489662}{0.000000000999999999}

    \tsc{10000000000.234567890113456789}{1.57079632669489662}{0.000000000099999999}
    \tsc{100000000000.234567890113456789}{1.57079632678489662}{0.000000000009999999}
    \tsc{1000000000000.234567890113456789}{1.57079632679389662}{0.000000000000999999}
    \tsc{10000000000000.234567890113456789}{1.57079632679479662}{0.000000000000099999}
    \tsc{100000000000000.234567890113456789}{1.57079632679488662}{0.000000000000009999}
    \tsc{1000000000000000.234567890113456789}{1.57079632679489562}{0.000000000000000999}
    \tsc{10000000000000000.234567890113456789}{1.57079632679489652}{0.000000000000000099}
    \tsc{100000000000000000.234567890113456789}{1.57079632679489661}{0.000000000000000009}
     \tsc{0.}{0.}{1.570796326794896619}
    \tsc{-0.1}{-0.099668652491162029}{1.670464979286058648}
    \tsc{-0.22}{-0.216550304976089278}{1.787346631770985897}
    \tsc{-0.333}{-0.321450524402644595}{1.892246851197541214}
    \tsc{-0.4444}{-0.418187215564994362}{1.988983542359890981}
    \tsc{-0.55555}{-0.507094259099305631}{2.07789058589420225}
    \tsc{-0.666666}{-0.588002142008964001}{2.15879846880386062}
    \tsc{-0.7777777}{-0.661043120389146583}{2.231839447184043202}
    \tsc{-0.88888888}{-0.726642335716208364}{2.297438662511104983}
    \tsc{-0.999999999}{-0.785398162897448356}{2.356194489692344975}
    \tsc{-1.}{-0.78539816339744831}{2.356194490192344929}
    \tsc{-1.2345678901}{-0.88998749346786801}{2.460783820262764629}
    \tsc{-2.23456789011}{-1.150011837102468973}{2.720808163897365592}
    \tsc{-4.23456789012}{-1.338893311505790293}{2.909689638300686912}
    \tsc{-8.2345678901134}{-1.449948794166153296}{3.020745120961049915}
    \tsc{-16.234567890113456}{-1.50927709513268111}{3.080073421927577729}
    \tsc{-32.23456789011345678}{-1.53978367639978028}{3.110580003194676899}
    \tsc{-64.234567890113456789}{-1.555229642723458197}{3.126025969518354816}
    \tsc{-100.234567890113456789}{-1.560820059669425338}{3.131616386464321957}
    \tsc{-1000.234567890113456789}{-1.569796561640876217}{3.140592888435772836}
    \tsc{-10000.234567890113456789}{-1.570696329140853809}{3.141492655935750428}
    \tsc{-100000.234567890113456789}{-1.570786326818353686}{3.141582653613250305}
    \tsc{-1000000.234567890113456789}{-1.570795326795131187}{3.141591653590027806}
    \tsc{-10000000.234567890113456789}{-1.570796226794898965}{3.141592553589795584}

    \tsc{-100000000.234567890113456789}{-1.570796316794896643}{3.141592643589793262}
    \tsc{-1000000000.234567890113456789}{-1.57079632579489662}{3.141592652589793239}
    \tsc{-10000000000.234567890113456789}{-1.57079632669489662}{3.141592653489793239}
    \tsc{-100000000000.234567890113456789}{-1.57079632678489662}{3.141592653579793239}
    \tsc{-1000000000000.234567890113456789}{-1.57079632679389662}{3.141592653588793239}
    \tsc{-10000000000000.234567890113456789}{-1.57079632679479662}{3.141592653589693239}
    \tsc{-100000000000000.234567890113456789}{-1.57079632679488662}{3.141592653589783239}
    \tsc{-1000000000000000.234567890113456789}{-1.57079632679489562}{3.141592653589792239}
    \tsc{-10000000000000000.234567890113456789}{-1.57079632679489652}{3.141592653589793139}
    \tsc{-100000000000000000.234567890113456789}{-1.57079632679489661}{3.141592653589793229}
:::

Example of \\FPexp
------------------

::: {.container .ltx-source}
    % The command \testeq checks that its arguments are equal 
    %Test exp(x) for all integers x (precomputed)
    \FPexp\foo{0}  \testeq\foo{1.}
    \FPexp\foo{1}  \testeq\foo{2.718281828459045235}
    \FPexp\foo{2}  \testeq\foo{7.389056098930650227}
    \FPexp\foo{3}  \testeq\foo{20.085536923187667741}
    \FPexp\foo{4}  \testeq\foo{54.598150033144239078}
    \FPexp\foo{5}  \testeq\foo{148.413159102576603421}
    \FPexp\foo{6}  \testeq\foo{403.428793492735122608}
    \FPexp\foo{7}  \testeq\foo{1096.633158428458599264}
    \FPexp\foo{8}  \testeq\foo{2980.957987041728274744}
    \FPexp\foo{9}  \testeq\foo{8103.08392757538400771}
    \FPexp\foo{10} \testeq\foo{22026.465794806716516958}
    \FPexp\foo{11} \testeq\foo{59874.141715197818455326}
    \FPexp\foo{12} \testeq\foo{162754.791419003920808005}
    \FPexp\foo{13} \testeq\foo{442413.392008920503326103}
    \FPexp\foo{14} \testeq\foo{1202604.284164776777749237}
    \FPexp\foo{15} \testeq\foo{3269017.372472110639301855}
    \FPexp\foo{16} \testeq\foo{8886110.520507872636763024}
    \FPexp\foo{17} \testeq\foo{24154952.753575298214775435}
    \FPexp\foo{18} \testeq\foo{65659969.137330511138786503}
    \FPexp\foo{19} \testeq\foo{178482300.963187260844910034}
    \FPexp\foo{20} \testeq\foo{485165195.409790277969106831}
    \FPexp\foo{21} \testeq\foo{1318815734.483214697209998884}
    \FPexp\foo{22} \testeq\foo{3584912846.131591561681159946}
    \FPexp\foo{23} \testeq\foo{9744803446.248902600034632685}
    \FPexp\foo{24} \testeq\foo{26489122129.843472294139162153}
    \FPexp\foo{25} \testeq\foo{72004899337.385872524161351466}
    \FPexp\foo{26} \testeq\foo{195729609428.838764269776397876}
    \FPexp\foo{27} \testeq\foo{532048240601.798616683747304341}
    \FPexp\foo{28} \testeq\foo{1446257064291.475173677047422997}
    \FPexp\foo{29} \testeq\foo{3931334297144.042074388620580844}
    \FPexp\foo{30} \testeq\foo{10686474581524.462146990468650741}
    \FPexp\foo{31} \testeq\foo{29048849665247.42523108568211168}
    \FPexp\foo{32} \testeq\foo{78962960182680.695160978022635108}
    \FPexp\foo{33} \testeq\foo{214643579785916.064624297761531261}
    \FPexp\foo{34} \testeq\foo{583461742527454.881402902734610391}
    \FPexp\foo{35} \testeq\foo{1586013452313430.72812964462577466}
    \FPexp\foo{36} \testeq\foo{4311231547115195.227113422292856925}
    \FPexp\foo{37} \testeq\foo{11719142372802611.308772939791190195}
    \FPexp\foo{38} \testeq\foo{31855931757113756.220328671701298646}
    \FPexp\foo{39} \testeq\foo{86593400423993746.953606932719264934}
    \FPexp\foo{40} \testeq\foo{235385266837019985.407899910749034805}
    \FPexp\foo{41} \testeq\foo{639843493530054949.222663403515570819}

    %Test exp(x) for all negative integers x (precomputed)
    \FPexp\foo{-0}  \testeq\foo{1.}
    \FPexp\foo{-1}  \testeq\foo{0.367879441171442322}
    \FPexp\foo{-2}  \testeq\foo{0.135335283236612692}
    \FPexp\foo{-3}  \testeq\foo{0.049787068367863943}
    \FPexp\foo{-4}  \testeq\foo{0.01831563888873418}
    \FPexp\foo{-5}  \testeq\foo{0.006737946999085467}
    \FPexp\foo{-6}  \testeq\foo{0.002478752176666358}
    \FPexp\foo{-7}  \testeq\foo{0.000911881965554516}
    \FPexp\foo{-8}  \testeq\foo{0.000335462627902512}
    \FPexp\foo{-9}  \testeq\foo{0.00012340980408668}
    \FPexp\foo{-10} \testeq\foo{0.000045399929762485}
    \FPexp\foo{-11} \testeq\foo{0.000016701700790246}
    \FPexp\foo{-12} \testeq\foo{0.000006144212353328}
    \FPexp\foo{-13} \testeq\foo{0.000002260329406981}
    \FPexp\foo{-14} \testeq\foo{0.000000831528719104}
    \FPexp\foo{-15} \testeq\foo{0.000000305902320502}
    \FPexp\foo{-16} \testeq\foo{0.000000112535174719}
    \FPexp\foo{-17} \testeq\foo{0.000000041399377188}
    \FPexp\foo{-18} \testeq\foo{0.000000015229979745}
    \FPexp\foo{-19} \testeq\foo{0.000000005602796438}
    \FPexp\foo{-20} \testeq\foo{0.000000002061153622}
    \FPexp\foo{-21} \testeq\foo{0.000000000758256043}
    \FPexp\foo{-22} \testeq\foo{0.000000000278946809}
    \FPexp\foo{-23} \testeq\foo{0.000000000102618796}
    \FPexp\foo{-24} \testeq\foo{0.000000000037751345}
    \FPexp\foo{-25} \testeq\foo{0.000000000013887944}
    \FPexp\foo{-26} \testeq\foo{0.000000000005109089}
    \FPexp\foo{-27} \testeq\foo{0.000000000001879529}
    \FPexp\foo{-28} \testeq\foo{0.00000000000069144}
    \FPexp\foo{-29} \testeq\foo{0.000000000000254367}
    \FPexp\foo{-30} \testeq\foo{0.000000000000093576}
    \FPexp\foo{-31} \testeq\foo{0.000000000000034425}
    \FPexp\foo{-32} \testeq\foo{0.000000000000012664}
    \FPexp\foo{-33} \testeq\foo{0.000000000000004659}
    \FPexp\foo{-34} \testeq\foo{0.000000000000001714}
    \FPexp\foo{-35} \testeq\foo{0.000000000000000631}
    \FPexp\foo{-36} \testeq\foo{0.000000000000000232}
    \FPexp\foo{-37} \testeq\foo{0.000000000000000085}
    \FPexp\foo{-38} \testeq\foo{0.000000000000000031}
    \FPexp\foo{-39} \testeq\foo{0.000000000000000012}
    \FPexp\foo{-40} \testeq\foo{0.000000000000000004}
    \FPexp\foo{-41} \testeq\foo{0.000000000000000002}
    \FPexp\foo{-42} \testeq\foo{0.000000000000000001}

    %Test exp(x) for other numbers
    \FPexp\foo{12.123456789012345678}    \testeq\foo{184140.952405940494102469}
    \FPexp\foo{-12.123456789012345678}   \testeq\foo{0.000005430622503762}
    \FPexp\foo{9.9123456789012345678}    \testeq\foo{20177.949513353417694403}
    \FPexp\foo{-9.9123456789012345678}   \testeq\foo{0.000049559049562405}
    \FPexp\foo{8.89123456789012345678}   \testeq\foo{7267.986469715274219469}
    \FPexp\foo{-8.89123456789012345678}  \testeq\foo{0.000137589689271831}
    \FPexp\foo{7.789123456789012345678}  \testeq\foo{2414.200503413830214843}
    \FPexp\foo{-7.789123456789012345678} \testeq\foo{0.000414215802948403}
:::

Example of \\FPln
-----------------

::: {.container .ltx-source}
    %The command \testeq checks that its arguments are equal 
    %\ln(x) is precomputed if x is a power of ten  
    \FPln\foo{1} \testeq\foo{0.}
    \FPln\foo{10} \testeq\foo{2.302585092994045684}
    \FPln\foo{100} \testeq\foo{4.605170185988091368}
    \FPln\foo{1000} \testeq\foo{6.907755278982137052}
    \FPln\foo{10000} \testeq\foo{9.210340371976182736}
    \FPln\foo{100000} \testeq\foo{11.51292546497022842}
    \FPln\foo{1000000} \testeq\foo{13.815510557964274104}
    \FPln\foo{10000000} \testeq\foo{16.118095650958319788}
    \FPln\foo{100000000} \testeq\foo{18.420680743952365472}
    \FPln\foo{1000000000} \testeq\foo{20.723265836946411156}
    \FPln\foo{10000000000} \testeq\foo{23.02585092994045684}
    \FPln\foo{100000000000} \testeq\foo{25.328436022934502524}
    \FPln\foo{1000000000000} \testeq\foo{27.631021115928548208}
    \FPln\foo{10000000000000} \testeq\foo{29.933606208922593892}
    \FPln\foo{100000000000000} \testeq\foo{32.236191301916639576}
    \FPln\foo{1000000000000000} \testeq\foo{34.53877639491068526}
    \FPln\foo{10000000000000000} \testeq\foo{36.841361487904730944}
    \FPln\foo{100000000000000000} \testeq\foo{39.143946580898776628}
    \FPln\foo{999999999999999999.99999999999} \testeq\foo{41.4465316738928223}

    % compute ln of factorial of 100
    \count0=1
    \def\foo{0}
    \loop \advance\count0 by 1\edef\bar{\the\count0}
    \FPln\bar\bar\FPadd\foo\foo\bar
    \ifnum \count0<100 \repeat
    \testeq\foo{363.7393755555634891072}
    % should be 363.73937555556349014407...
:::

Example of \\FPlsolve, \\FPqsolve, \\FPcsolve, \\FPqqsolve
----------------------------------------------------------

::: {.container .ltx-source}
    %The command \testeq checks that its arguments are equal 
    % case of degree one 
    \FPlsolve\foo{2}{3} \testeq\foo{-1.5} \ifnum\count0=1 \else\uerror\fi
    % case of degree two (2 then 0 roots) 
    \FPqsolve\foo\bar{1.7}{1.87}{-4.692}
    \ifnum\count0=2 \else\uerror\fi % roots are 1.2 and -2.3  
    \testeq\foo{1.199999999999999978}\testeq\bar{-2.299999999999999978}

    \FPqsolve\foo\bar{1.7}{5.1}{22.1} 
    \ifnum\count0=0 \else\uerror\fi

    % case of degree three 
    \FPcsolve\foo\bar\gee{1.7}{6.63}{0.544}{-13.1376}
    \ifnum\count0=3 \else\uerror\fi% roots are 1.2, -2.8 and -2.3 
    \testeq\foo{1.199999999999999986}
    \testeq\bar{-2.79999999999999993}
    \testeq\gee{-2.300000000000000055}

    \FPcsolve\foo\bar\gee{1.7}{13.43}{47.09}{108.29}
    \ifnum\count0=1 \else\uerror\fi% single root -4.9 
    \testeq\foo{-4.900000000000000077}

    % case of degree four 
    \FPqqsolve\foo\bar\uu\vv{1.7}0{1.87}0{-4.692}
    \ifnum\count0=2 \else\uerror\fi % 2 opposite roots  
    \testeq\foo{1.095445115010332206}
    \testeq\bar{-1.095445115010332206}

    \FPqqsolve\foo\bar\uu\vv{1.7}0{5.1}0{22.1} 
        % 2 pairs of imaginary opposite roots  
    \ifnum\count0=0 \else\uerror\fi

    \FPqqsolve\foo\bar\uu\vv{1}0{-13}0{36}
    \ifnum\count0=4 \else\uerror\fi%  roots are 2, -2, 3 -4  
    \testeq\foo{1.999999999999999995}
    \testeq\bar{-1.999999999999999995}
    \testeq\uu{2.999999999999999967}
    \testeq\vv{-2.999999999999999967}

    \FPqqsolve\foo\bar\uu\vv{0.25}{-2}{4.25}{-2}{0.25}
    \ifnum\count0=4 \else\uerror\fi% 4 roots  
    \testeq\foo{2.618033988749894842}
    \testeq\bar{0.381966011250105161}
    \testeq\uu{4.791287847477919982}
    \testeq\vv{0.208712152522080013}
    \FPqqsolve\foo\bar\uu\vv{1.7}{1.87}{-4.692}{1.87}{1.7}
    \ifnum\count0=2 \else\uerror\fi% 2 roots  
    \testeq\foo{-0.420204102886728779}
    \testeq\bar{-2.379795897113271197}
    \FPqqsolve\foo\bar\uu\vv{6}{-5}{13}{-5}{6}
    \ifnum\count0=0 \else\uerror\fi% no root  

    \FPqqsolve\foo\bar\uu\vv{6}{-5}{13}{-5}{6.1}
    \ifnum\count0=0 \else\uerror\fi% no root  

    \FPqqsolve\foo\bar\uu\vv{0.25}{-2}{4.25}{-2}{0.251}
    \ifnum\count0=4 \else\uerror\fi
    \testeq\foo{0.379595677692027994}
    \testeq\bar{0.210831989170684696}
    \testeq\uu{4.791196750515405957}
    \testeq\vv{2.618375582621881353}
    \FPqqsolve\foo\bar\uu\vv{1.7}{1.87}{-4.692}{1.87}{1.701}
    \ifnum\count0=2 \else\uerror\fi
    \testeq\foo{-0.420362831504803625}
    \testeq\bar{-2.37976786558364871}


    \FPqqsolve\foo\bar\uu\vv{1.7}0{1.87}{0.00000001}{-4.692}
    %\ifnum\count0=2 \else\uerror\fi
    %\show\foo\show\bar\show\uu\show\vv
    \FPqqsolve\foo\bar\uu\vv{1.7}{0.001}{1.87}0{-4.692}
    \testeq\foo{9.199999802152560780}
    \testeq\foo{0.000000149424471035}
    \testeq\foo{1.095344292320422276}
    \testeq\foo{-1.095545972998688846}
:::

Example of \\FPround
--------------------

::: {.container .ltx-source}
    %The command \testeq checks that its arguments are equal
    \FPround\foo{12.1} 0 \testeq \foo{12.}
    \FPround\foo{12.6} 0 \testeq \foo{13.}
    \FPround\foo{12.500000000000000000001} 0 \testeq \foo{13.}
    \FPround\foo{12.1} 1 \testeq \foo{12.1}
    \FPround\foo{12.123456789} 1 \testeq \foo{12.1}
    \FPround\foo{12.1734567890000003} 1 \testeq \foo{12.2}
    \FPround\foo{12.123456789} 2 \testeq \foo{12.12}
    \FPround\foo{12.1273456789} 2 \testeq \foo{12.13}
    \FPround\foo{12.123456789} 3 \testeq \foo{12.123}
    \FPround\foo{12.12373456789} 3 \testeq \foo{12.124}
    \FPround\foo{12.1234156789} 4 \testeq \foo{12.1234}
    \FPround\foo{12.123456789} 4 \testeq \foo{12.1235}
    \FPround\foo{12.91234156789} 5 \testeq \foo{12.91234}
    \FPround\foo{12.9123456789} 5 \testeq \foo{12.91235}
    \FPround\foo{12.9999956789} 5 \testeq \foo{13.}
    \FPround\foo{12.891234156789} 6 \testeq \foo{12.891234}
    \FPround\foo{12.89123456789} 6 \testeq \foo{12.891235}
    \FPround\foo{12.7891234156789} 7 \testeq \foo{12.7891234}
    \FPround\foo{12.789123456789} 7 \testeq \foo{12.7891235}
    \FPround\foo{12.67891234156789} 8 \testeq \foo{12.67891234}
    \FPround\foo{12.6789123456789} 8 \testeq \foo{12.67891235}
    \FPround\foo{12.567891234156789} 9 \testeq \foo{12.567891234}
    \FPround\foo{12.56789123456789} 9 \testeq \foo{12.567891235}
    \FPround\foo{12.4567891234156789} {10} \testeq \foo{12.4567891234}
    \FPround\foo{12.456789123456789} {10} \testeq \foo{12.4567891235}
    \FPround\foo{12.34567891234156789} {11} \testeq \foo{12.34567891234}
    \FPround\foo{12.23456789123456789} {12} \testeq \foo{12.234567891235}
    \FPround\foo{12.234567891234156789} {12} \testeq \foo{12.234567891234}
    \FPround\foo{12.123456789123456789} {13} \testeq \foo{12.1234567891235}
    \FPround\foo{12.1234567891234156789} {13} \testeq \foo{12.1234567891234}
    \FPround\foo{12.0123456789123456789} {14} \testeq \foo{12.01234567891235}
    \FPround\foo{12.01234567891234156789} {14} \testeq \foo{12.01234567891234}
    \FPround\foo{12.90123456789123456789} {15} \testeq \foo{12.901234567891235}
    \FPround\foo{12.901234567891234156789} {15} \testeq \foo{12.901234567891234}
    \FPround\foo{12.890123456789123456789} {16} \testeq \foo{12.8901234567891235}
    \FPround\foo{12.8901234567891234156789} {16} \testeq \foo{12.8901234567891234}
    \FPround\foo{12.7890123456789123456789} {17} \testeq \foo{12.78901234567891235}
    \FPround\foo{12.78901234567891234156789} {17} \testeq \foo{12.78901234567891234}
    \FPround\foo{12.67890123456789123456789} {18} \testeq \foo{12.678901234567891234}
    \FPround\foo{12.678901234567891234156789} {18} \testeq \foo{12.678901234567891234}
    \FPround\foo{12.67890123456789123456789} {19} \testeq \foo{12.678901234567891234}
    \FPround\foo{12.678901234567891234156789} {19} \testeq \foo{12.678901234567891234}
    \FPround\foo{12.9999999996}9 \testeq\foo{13.}
:::

Example of \\FPsin, \\FPcos, \\FPsincos, \\FPtan, \\FPcot, and \\FPtancot
-------------------------------------------------------------------------

::: {.container .ltx-source}
:

    \def\tsc(#1,#2,#3){%Test and example of \FPsin, \FPcos, \FPsincos
                       % \FPtan, \FPcot, and \FPtancot
    \def\arg{#1}%
    \FPsin\csr\arg\testeq\csr{#2}% test that sin(#1)=#2
    \FPcos\ccr\arg\testeq\ccr{#3}% test that cos(#1)=#3
    \FPdiv\tanval{#2}{#3}% is sin/cos
    \FPdiv\cotval{#3}{#2}% is cos/sin
    \FPtan\atr\arg\xtesteq\atr\tanval% test tangent
    \FPcot\ctr\arg\xtesteq\ctr\cotval% test cotangent
    \FPsincos\scs\scc\arg\testeq\scs{#2}\testeq\scc{#3}% test \FPsincos
    \FPtancot\tct\tcc\arg\xtesteq\tct\tanval\xtesteq\tcc\cotval% test \FPtancot
    }
    \def\xtesteq#1#2{% compare #1 with #2 expanded
    \xdef\tmp{#2}\ifx#1\tmp\else \typeout{______#2}\show #1\uerror\fi}

    \tsc(0.1012345678901232456789  ,0.1010617404468389,0.994880155907160391)
    \tsc(-0.1012345678901232456789,-0.1010617404468389,0.994880155907160391)
    \tsc(0.3012345678901232456789  ,0.296699408905774917,0.954970921418533965)
    \tsc(-0.3012345678901232456789,-0.296699408905774917,0.954970921418533965)
    \tsc(0.5012345678901232456789  ,0.480508608220765167,0.876990009877959334)
    \tsc(-0.5012345678901232456789,-0.480508608220765167,0.876990009877959334)
    \tsc(0.7012345678901232456789  ,0.64516144565859153,0.764046274145562632)
    \tsc(-0.7012345678901232456789,-0.64516144565859153,0.764046274145562632)
    \tsc(0.9012345678901232456789  ,0.784093732182682786,0.620642424550426072)
    \tsc(-0.9012345678901232456789,-0.784093732182682786,0.620642424550426072)
    \tsc(1.1012345678901232456789  ,0.891766675955506368,0.452495520038891548)
    \tsc(-1.1012345678901232456789,-0.891766675955506368,0.452495520038891548)
    \tsc(1.3012345678901232456789  ,0.963887696490462379,0.266309047075592758)
    \tsc(-1.3012345678901232456789,-0.963887696490462379,0.266309047075592758)
    \tsc(1.5012345678901232456789  ,0.997581556289863304,0.069505672792185076)
    \tsc(-1.5012345678901232456789,-0.997581556289863304,0.069505672792185076)
    \tsc(1.7012345678901232456789  ,0.991504987490630185,-0.130068673327612908)
    \tsc(-1.7012345678901232456789,-0.991504987490630185,-0.130068673327612908)
    \tsc(1.9012345678901232456789  ,0.945900243715066732,-0.324457591897273006)
    \tsc(-1.9012345678901232456789,-0.945900243715066732,-0.324457591897273006)
    \tsc(2.1012345678901232456789  ,0.862585442183413576,-0.505911410163128142)
    \tsc(-2.1012345678901232456789,-0.862585442183413576,-0.505911410163128142)
    \tsc(2.3012345678901232456789  ,0.744882081117677936,-0.667196137001554491)
    \tsc(-2.3012345678901232456789,-0.744882081117677936,-0.667196137001554491)
    \tsc(2.5012345678901232456789  ,0.597482622089115954,-0.801881859316891298)
    \tsc(-2.5012345678901232456789,-0.597482622089115955,-0.801881859316891297)
    \tsc(2.7012345678901232456789  ,0.4262634163833055,-0.904599082385800744)
    \tsc(-2.7012345678901232456789,-0.426263416383305501,-0.904599082385800743)
    \tsc(2.9012345678901232456789  ,0.238050433418288991,-0.971252794667466972)
    \tsc(-2.9012345678901232456789,-0.238050433418288992,-0.971252794667466972)
    \tsc(3.1012345678901232456789  ,0.040347130884468172,-0.999185722991172245)
    \tsc(-3.1012345678901232456789,-0.040347130884468173,-0.999185722991172245)
    \tsc(3.3012345678901232456789 ,-0.158964684434982212,-0.987284269652103048)
    \tsc(-3.3012345678901232456789 ,0.158964684434982211,-0.987284269652103048)
    \tsc(3.5012345678901232456789 ,-0.351939079428079982,-0.936022908037680247)
    \tsc(-3.5012345678901232456789 ,0.351939079428079981,-0.936022908037680247)
    \tsc(3.7012345678901232456789 ,-0.530882773932368332,-0.847445266870889957)
    \tsc(-3.7012345678901232456789 ,0.530882773932368331,-0.847445266870889957)
    \tsc(3.9012345678901232456789 ,-0.688661847537443519,-0.725082657182141475)
    \tsc(-3.9012345678901232456789 ,0.688661847537443518,-0.725082657182141476)
    \tsc(4.1012345678901232456789 ,-0.818986146479329999,-0.5738132900821812)
    \tsc(-4.1012345678901232456789 ,0.818986146479329999,-0.5738132900821812)
    \tsc(4.3012345678901232456789 ,-0.916660052221322069,-0.399667797879192535)
    \tsc(-4.3012345678901232456789 ,0.916660052221322069,-0.399667797879192535)
    \tsc(4.5012345678901232456789 ,-0.977789614369319932,-0.209588811799429354)
    \tsc(-4.5012345678901232456789 ,0.977789614369319932,-0.209588811799429354)
    \tsc(4.7012345678901232456789 ,-0.999937790185971389,-0.011154181188965009)
    \tsc(-4.7012345678901232456789 ,0.999937790185971389,-0.011154181188965009)
    \tsc(4.9012345678901232456789 ,-0.982221601794077009,0.187725131426449178)
    \tsc(-4.9012345678901232456789 ,0.982221601794077009,0.187725131426449178)
    \tsc(5.1012345678901232456789 ,-0.925347337718156243,0.379120435452799748)
    \tsc(-5.1012345678901232456789 ,0.925347337718156243,0.379120435452799748)
    \tsc(5.3012345678901232456789 ,-0.831582395389797154,0.555401404101364395)
    \tsc(-5.3012345678901232456789 ,0.831582395389797154,0.555401404101364395)
    \tsc(5.5012345678901232456789 ,-0.704664887167245378,0.709540271438889748)
    \tsc(-5.5012345678901232456789 ,0.704664887167245378,0.709540271438889748)
    \tsc(5.7012345678901232456789 ,-0.54965461359197653,0.835392007237952312)
    \tsc(-5.7012345678901232456789 ,0.54965461359197653,0.835392007237952312)
    \tsc(5.9012345678901232456789 ,-0.372731345108231537,0.92793929994036162)
    \tsc(-5.9012345678901232456789 ,0.372731345108231537,0.92793929994036162)
    \tsc(6.1012345678901232456789 ,-0.180948454116798069,0.983492581035943058)
    \tsc(-6.1012345678901232456789 ,0.180948454116798069,0.983492581035943058)
    \tsc(6.3012345678901232456789  ,0.018048280724405105,0.999837116515931842)
    \tsc(-6.3012345678901232456789,-0.018048280724405105,0.999837116515931842)
    \tsc(6.7012345678901232456789  ,0.405978479876358888,0.913882636817923606)
    \tsc(-6.7012345678901232456789,-0.405978479876358888,0.913882636817923606)
    \tsc(22.6012345678901232456789,-0.572937941778857506,-0.819598752360084116)
    \tsc(-22.6012345678901232456789,0.572937941778857505,-0.819598752360084116)
    \tsc(333.6012345678901232456789,0.558364699503853438,0.829595601692759368)
    \tsc(-333.6012345678901232456789,-0.558364699503853438,0.829595601692759368)
    \tsc(4444.6012345678901232456789,0.683371137707483341,-0.730071152798396659)
    \tsc(-4444.6012345678901232456789,-0.683371137707483342,-0.730071152798396658)
    \tsc(55555.6012345678901232456789,-0.317651344590243807,0.94820758448770604)
    \tsc(-55555.6012345678901232456789,0.317651344590243807,0.94820758448770604)
    \tsc(666666.6012345678901232456789,0.975943132754450349,-0.218025231634848405)
    \tsc(-666666.6012345678901232456789,-0.975943132754450349,-0.218025231634848405)
    \tsc(7777777.6012345678901232456789,-0.999955236694279961,0.009461744431474613)
    \tsc(-7777777.6012345678901232456789,0.999955236694279961,0.009461744431474613)
    \tsc(88888888.6012345678901232456789,0.042909218626836249,0.9990789753352006)
    \tsc(-88888888.6012345678901232456789,-0.042909218626836249,0.9990789753352006)
    \tsc(1999999999.6012345678901232456789,0.686035088730874198,0.727568455219178372)
    \tsc(-1999999999.6012345678901232456789,-0.686035088730874198,0.727568455219178372)
    \tsc(11111111111.6012345678901232456789,-0.825737644766692954,-0.564054378597626699)
    \tsc(-11111111111.6012345678901232456789,0.825737644766692954,-0.564054378597626699)
:::

Example of \\FPtrunc
--------------------

::: {.container .ltx-source}
    %The command \testeq checks that its arguments are equal
    \FPtrunc\foo{12.1} 0 \testeq \foo{12.}
    \FPtrunc\foo{12.6} 0 \testeq \foo{12.}
    \FPtrunc\foo{12.500000000000000000001} 1 \testeq \foo{12.5}
    \FPtrunc\foo{12.1} 1 \testeq \foo{12.1}
    \FPtrunc\foo{12.123456789} 1 \testeq \foo{12.1}
    \FPtrunc\foo{12.1734567890000003} 1 \testeq \foo{12.1}
    \FPtrunc\foo{12.123456789} 2 \testeq \foo{12.12}
    \FPtrunc\foo{12.1273456789} 2 \testeq \foo{12.12}
    \FPtrunc\foo{12.123456789} 3 \testeq \foo{12.123}
    \FPtrunc\foo{12.12373456789} 3 \testeq \foo{12.123}
    \FPtrunc\foo{12.1234156789} 4 \testeq \foo{12.1234}
    \FPtrunc\foo{12.123456789} 4 \testeq \foo{12.1234}
    \FPtrunc\foo{12.91234156789} 5 \testeq \foo{12.91234}
    \FPtrunc\foo{12.9123456789} 5 \testeq \foo{12.91234}
    \FPtrunc\foo{12.9999956789} 5 \testeq \foo{12.99999}
    \FPtrunc\foo{12.891234156789} 6 \testeq \foo{12.891234}
    \FPtrunc\foo{12.89123456789} 6 \testeq \foo{12.891234}
    \FPtrunc\foo{12.7891234156789} 7 \testeq \foo{12.7891234}
    \FPtrunc\foo{12.789123456789} 7 \testeq \foo{12.7891234}
    \FPtrunc\foo{12.67891234156789} 8 \testeq \foo{12.67891234}
    \FPtrunc\foo{12.6789123456789} 8 \testeq \foo{12.67891234}
    \FPtrunc\foo{12.567891234156789} 9 \testeq \foo{12.567891234}
    \FPtrunc\foo{12.56789123456789} 9 \testeq \foo{12.567891234}
    \FPtrunc\foo{12.4567891234156789} {10} \testeq \foo{12.4567891234}
    \FPtrunc\foo{12.456789123456789} {10} \testeq \foo{12.4567891234}
    \FPtrunc\foo{12.34567891234156789} {11} \testeq \foo{12.34567891234}
    \FPtrunc\foo{12.23456789123456789} {12} \testeq \foo{12.234567891234}
    \FPtrunc\foo{12.234567891234156789} {12} \testeq \foo{12.234567891234}
    \FPtrunc\foo{12.123456789123456789} {13} \testeq \foo{12.1234567891234}
    \FPtrunc\foo{12.1234567891234156789} {13} \testeq \foo{12.1234567891234}
    \FPtrunc\foo{12.0123456789123456789} {14} \testeq \foo{12.01234567891234}
    \FPtrunc\foo{12.01234567891234156789} {14} \testeq \foo{12.01234567891234}
    \FPtrunc\foo{12.90123456789123456789} {15} \testeq \foo{12.901234567891234}
    \FPtrunc\foo{12.901234567891234156789} {15} \testeq \foo{12.901234567891234}
    \FPtrunc\foo{12.890123456789123456789} {16} \testeq \foo{12.8901234567891234}
    \FPtrunc\foo{12.8901234567891234156789} {16} \testeq \foo{12.8901234567891234}
    \FPtrunc\foo{12.7890123456789123456789} {17} \testeq \foo{12.78901234567891234}
    \FPtrunc\foo{12.78901234567891234156789} {17} \testeq \foo{12.78901234567891234}
    \FPtrunc\foo{12.67890123456789123456789} {18} \testeq \foo{12.678901234567891234}
    \FPtrunc\foo{12.678901234567891234156789} {18} \testeq \foo{12.678901234567891234}
    \FPtrunc\foo{12.67890123456789123456789} {19} \testeq \foo{12.678901234567891234}
    \FPtrunc\foo{12.678901234567891234156789} {19} \testeq \foo{12.678901234567891234}
    \FPtrunc\foo{12.9999999996}9 \testeq\foo{12.999999999}
:::