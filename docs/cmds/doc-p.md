All commands, alphabetic order; letter P
========================================

| This page contains the description of the following commands
  [\\P](#cmd-P), [\\p@](#cmd-p-at), [page](#cmd-page),
  [\\pagebreak](#cmd-pagebreak), [\\pagecolor](#cmd-pagecolor),
  [\\pagedepth](#cmd-pagedepth), [\\pagediscards](#cmd-pagediscards),
  [\\pagefilllstretch](#cmd-pagefilllstretch),
  [\\pagefillstretch](#cmd-pagefillstretch),
  [\\pagefilstretch](#cmd-pagefilstretch), [\\pagegoal](#cmd-pagegoal),
  [\\pagenumbering](#cmd-pagestyle), [\\pageref](#cmd-pageref),
  [\\pageshrink](#cmd-pageshrink), [\\pagestretch](#cmd-pagestretch),
  [\\pagestyle](#cmd-pagestyle), [\\pagetotal](#cmd-pagetotal),
  [\\paperheight](#cmd-paperheight), [\\paperwidth](#cmd-paperheight),
  [\\par](#cmd-par), [\\paragraph](#cmd-paragraph),
  [\\paragraphmark](#cmd-paragraphmark), [\\parallel](#cmd-parallel),
  [\\parbox](#cmd-parbox), [\\parfillskip](#cmd-parfillskip),
  [\\parindent](#cmd-parindent), [\\parsep](#cmd-parsep),
  [\\parshape](#cmd-parshape), [\\parshapedimen](#cmd-parshapedimen),
  [\\parshapeindent](#cmd-parshapeindent),
  [\\parshapelength](#cmd-parshapelength), [\\parskip](#cmd-parskip),
  [\\part](#cmd-part), [\\partial](#cmd-partial),
  [\\partopsep](#cmd-partopsep), [\\patterns](#cmd-patterns),
  [\\pausing](#cmd-pausing), [\\penalty](#cmd-penalty),
  [\\perp](#cmd-perp), [\\\@persA](#cmd-pers), [\\\@persB](#cmd-pers),
  [\\pers](#cmd-pers), [\\persA](#cmd-pers), [\\persB](#cmd-pers),
  [\\phi](#cmd-phi), [\\Phi](#cmd-cphi), [\\pi](#cmd-pi),
  [\\Pi](#cmd-cpi), [\\pitchfork](#cmd-pitchfork),
  [\\\@plus](#cmd-plus), [\\pm](#cmd-pm), [\\pmod](#cmd-pmod),
  [\\pod](#cmd-pmod), [\\Pr](#cmd-Pr),
  [\\postdisplaypenalty](#cmd-postdisplaypenalty),
  [\\pounds](#cmd-pounds), [\\prec](#cmd-prec),
  [\\precapprox](#cmd-precapprox), [\\preccurlyeq](#cmd-preccurlyeq),
  [\\preceq](#cmd-preceq), [\\precnapprox](#cmd-precnapprox),
  [\\precneqq](#cmd-precneqq), [\\precnsim](#cmd-precnsim),
  [\\precsim](#cmd-precsim),
  [\\predisplaydirection](#cmd-predisplaydirection),
  [\\predisplaypenalty](#cmd-predisplaypenalty),
  [\\predisplaysize](#cmd-predisplaysize),
  [\\presetkeys](#cmd-presetkeys), [\\pretolerance](#cmd-pretolerance),
  [\\prevdepth](#cmd-prevdepth), [\\prevgraf](#cmd-prevgraf),
  [\\Prime](#cmd-cprime), [\\prime](#cmd-prime),
  [\\printglossary](#cmd-printindex), [\\printindex](#cmd-printindex),
  [\\prod](#cmd-prod), [\\ProcessOptions](#cmd-processoptions),
  [\\ProcessOptionsX](#cmd-processoptions), [\\projlim](#cmd-projlim),
  [\\propto](#cmd-propto), [\\protect](#cmd-protect),
  [\\protected](#cmd-protected),
  [\\provideboolean](#cmd-provideboolean),
  [\\providecommand](#cmd-providecommand),
  [\\ProvidesClass](#cmd-providesclass),
  [\\ProvidesFile](#cmd-providesclass),
  [\\ProvidesPackage](#cmd-providesclass),
  [\\ProvideTextCommand](doc-f.html#cmd-unimpfont),
  [\\ProvideTextCommandDeafault](doc-f.html#cmd-unimpfont),
  [\\psi](#cmd-psi), [\\Psi](#cmd-cpsi), [\\psfig](#cmd-psfig),
  [\\put](#cmd-put),
| and environments [participant](#env-participant)
  [participante](#env-participant), [participants](#env-participant),
  [participantes](#env-participant), [picture](#env-picture).

------------------------------------------------------------------------

\\P (constant) {#cmd-P}
--------------

The `\P` command translates to a pilcrow sign, ¶ or `&#xB6;`. It is
equivalent to `\textparagraph`. See description of the [latin supplement
characters](doc-chars.html#latin).

\\p@ (rigid length) {#cmd-p-at}
-------------------

You should not modify this length, so that it will be constantly equal
to one pt.

page (counter) {#cmd-page}
--------------

The page counter is the counter number zero. The page number is
incremented (in LaTeX) via `\stepcounter{page}` (this might reset some
other counters). In *Tralics*, the initial page number is one, and is
left unchanged. `\thepage` produces an arabic version of the page.

\\pagebreak {#cmd-pagebreak}
-----------

The `\pagebreak` command takes an optional argument. It is used to favor
a page break at this position in the text. This command is ignored in
*Tralics*.

\\pagecolor {#cmd-pagecolor}
-----------

Translation is a `<pagecolor>` element, see `` `\color ``
\<doc-c.html\#cmd-color\>\`\_\_.

\\pagedepth (rigid length) {#cmd-pagedepth}
--------------------------

In *Tralics*, you can assign a dimension to this variable, but the value
shown by `\the` is always zero. See `` `\pagetotal ``
\<\#cmd-pagetotal\>\`\_\_.

\\pagediscards (eTeX extension) {#cmd-pagediscards}
-------------------------------

The command is ignored in *Tralics*. See `` `\savingdiscards ``
\<doc-s.html\#cmd-savingdiscards\>\`\_\_ for explanations.

\\pagefilllstretch (rigid length) {#cmd-pagefilllstretch}
---------------------------------

In *Tralics*, you can assign a dimension to this variable, but the value
shown by `\the` is always zero. See `` `\pagetotal ``
\<\#cmd-pagetotal\>\`\_\_.

\\pagefillstretch (rigid length) {#cmd-pagefillstretch}
--------------------------------

In *Tralics*, you can assign a dimension to this variable, but the value
shown by `\the` is always zero. See `` `\pagetotal ``
\<\#cmd-pagetotal\>\`\_\_.

\\pagefilstretch (rigid length) {#cmd-pagefilstretch}
-------------------------------

In *Tralics*, you can assign a dimension to this variable, but the value
shown by `\the` is always zero. See `` `\pagetotal ``
\<\#cmd-pagetotal\>\`\_\_.

\\pagegoal (rigid length) {#cmd-pagegoal}
-------------------------

The variable `\pagegoal` is a dimension that holds the space reserved on
the current page for the text. It is `\vsize`, minus the size reserved
for the footnotes. You can change this variable.

In *Tralics*, `\showthe\pagegoal` always yields 0.0pt although
`\pagegoal=15pt` has been issued.

\\paperheight, \\paperwidth (rigid length) {#cmd-paperheight}
------------------------------------------

The default values of these parameters correspond to A4 paper. Class
options of the form letterpaper should change these values.

\\pageref {#cmd-pageref}
---------

Translation of `\pageref{x}` is `<ref target='uid2' rend='page'/>`. See
`` `\anchor `` \<doc-a.html\#cmd-anchor\>\`\_\_ for explanations on how
the target (here uid2) is constructed for the argument \`x\'.

\\pagestretch (rigid length) {#cmd-pagestretch}
----------------------------

In *Tralics*, you can assign a dimension to this variable, but the value
shown by `\the` is always zero. See `` `\pagetotal ``
\<\#cmd-pagetotal\>\`\_\_.

\\pageshrink (rigid length) {#cmd-pageshrink}
---------------------------

In *Tralics*, you can assign a dimension to this variable, but the value
shown by `\the` is always zero. See `` `\pagetotal ``
\<\#cmd-pagetotal\>\`\_\_.

\\pagestyle, \\pagenumbering, \\thispagestyle {#cmd-pagestyle}
---------------------------------------------

The commands `\pagestyle`, `\thispagestyle` and `\pagenumbering` are not
interpreted by *Tralics*; they take an argument and construct a
`<pagestyle>` element. Example

::: {.container .ltx-source}
    \pagenumbering{arabic} \pagestyle{mypagestyle}\thispagestyle{plain}
:::

Translation

::: {.container .xml_out}
    <pagestyle numbering='arabic'/> 
    <pagestyle style='mypagestyle'/>
    <pagestyle this-style='plain'/>
:::

\\pagetotal (rigid length) {#cmd-pagetotal}
--------------------------

TeX maintains in some registers, containing dimensions, the size of the
current page. It is possible (with care) to modify them. It is possible
to consult the values. In *Tralics*, `\pagetotal=100cm` puts one meter
into some variable, but `\showthe\pagetotal` will always return 0.0pt.
Page breaks are chosen in such a way as to minimize a cost, depending on
the penalty of the break (inserted by the user, or the line breaking
algorithm), and the badness that depends on how the glue of the page can
compensate the difference between `\pagetotal` and `\pagegoal`.

If you put a glue of value `1pt plus 2fill` and a glue of value
`3pt plus 4 fil minus 5filll`, the `\pagetotal` will hold the natural
height, namely 4pt. The stretch part is not 2fill (as would be the sum
of the two glues). It is the sum of `\pagestretch` and `\pagefilstretch`
(times fil) and `\pagefillstretch` (times fill) and `\pagefilllstretch`
(times filll). The shrink part is in `\pageshrink` (if its value is not
finite, a message of the form *Infinite glue shrinkage found on current
page* is issued). Finally, the `\pagedepth` holds the depth of the page;
this is the depth of the last box on the page, thus is a dimension, not
a glue.

\\par {#cmd-par}
-----

The `\par` command is used to terminate the current paragraph. There are
two aliases, `\endgraf` and `\@@par`. An empty line gives a `\par`.
Hence the following five lines of input

::: {.container .ltx-source}
    {\def\par{!\endgraf}
    Redefining par


    }
:::

are translated by *Tralics* into:

::: {.container .xml_out}
    <p>Redefining par !</p>
    <p>!</p>
:::

| Note: after the letters \`par\', there is a newline character that TeX
  converts into a space. This space is in general invisible, because TeX
  removes the last item in a paragraph if it is glue, before adding the
  `\parfillskip` glue.
| The next example shows that each empty line generates a `\par`, but
  the `\par` does nothing outside paragraph mode.

::: {.container .ltx-source}
    \count0=0
    {\def\par{\global\advance\count0by 1\endgraf}
    Redefining par



    \the\count0}
:::

gives

::: {.container .xml_out}
    <p>Redefining par</p>
    <p>3</p>
:::

\\paragraph {#cmd-paragraph}
-----------

The `\paragraph` command is used to divide a text in smaller parts.
There is also a counter `paragraph`, incremented by the command. See the
description of the `` `\part `` \<doc-p.html\#cmd-part\>\`\_\_ command.

\\paragraphmark {#cmd-paragraphmark}
---------------

The `\paragraphmark` command takes one argument and does nothing. You
can redefine it. It is used to mark paragraphs. See `` `\chaptermark ``
\<doc-c.html\#cmd-chaptermark\>\`\_\_ for an explanation of page marks.

\\parallel (math symbol) {#cmd-parallel}
------------------------

The `\parallel` command is valid only in math mode. It generates a
relation symbol: `<mo>&parallel;</mo>` (Unicode U+2225, ∥). See
description of the `` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\parbox {#cmd-parbox}
--------

You can say `\parbox[foo][bar][gee]{2cmPlus3mm}{some \it box  content}`.
The arguments are the same as those of the `` `minipage ``
\<doc-m.html\#env-minipage\>[\_\_ environment. The first three optional
arguments are ignored. After that comes a rubber length (in the example,
it is nearly 57pt plus 8.5pt), which is also ignored. The last argument
is translated as if it were ]{.title-ref}[vbox]{.title-ref}[. However,
the tokens from ]{.title-ref}[everyvbox]{.title-ref}[ are not inserted,
and ]{.title-ref}[ifvmode]{.title-ref}\` might be false.

\\parfillskip (rubber length) {#cmd-parfillskip}
-----------------------------

You can say `\parfillskip=10pt plus 2pt minus 3pt`. This explains to TeX
that it should put 10pt (maybe up to 2pt more, maybe up to 3pt less) of
glue between the right margin and the last word in a paragraph (default
is 0pt plus1fil). Unused by *Tralics*. (See
[scanglue](doc-s.html#fct-scanglue) for details of argument scanning).

\\parindent (rigid length) {#cmd-parindent}
--------------------------

You can say `\parindent=5mm`, as a result TeX will use 5mm as horizontal
space for `\indent`. In *Tralics*, the effect of `\indent` is to add a
flag on the attribute list of the current paragraph; no numerical value
is used. (See [scandimen](doc-s.html#fct-scandimen) for details of
argument scanning).

\\parshape {#cmd-parshape}
----------

When you say `\parshape3 1pt 102pt  3pt 104pt 5pt 106pt` then TeX will
construct a paragraph with a special shape. The first line has width
102pt, is indented by 1pt; the second line has width 104pt, is indented
by 3pt; the third line has width 106pt, is indented by 5pt; if the
paragraph has more then 3 lines, all lines after the third have the same
shape. This declaration applies only to the current paragraph. If you
say `\the\parshape`, you will see 3, the number of special lines in the
paragraph shape. (See [scandimen](doc-s.html#fct-scandimen) for details
of argument scanning).

The syntax is the same in *Tralics*, but nothing special happens. Note
that there are extensions in ε-TeX that allows you to access to all
parameters. As a consequence, in the current version of *Tralics*, the
dimensions are memorized somewhere.

\\parshapedimen (eTeX extension) {#cmd-parshapedimen}
--------------------------------

\\parshapeindent (eTeX extension) {#cmd-parshapeindent}
---------------------------------

\\parshapelength (eTeX extension) {#cmd-parshapelength}
---------------------------------

The commands `\parshapelength`, `\parshapeindent`, read an integer *n*;
they return the length or indentation of the line *n* in the current
parshape; the command `\parshapedimen` reads *2n* or *2n+1*, and returns
one of these quantities, depending on the parity of the argument.
Example: in the following code, the `\bad` macro is not called. (See
[scanint](doc-s.html#fct-scanint) for details of argument scanning).

::: {.container .ltx-source}
    \parshape 3 1pt 2pt 3pt 4pt 5pt 6pt
    \ifnum\parshape         = 3 \else\bad\fi
    \ifdim\parshapelength 1 = 2.0pt\else\bad\fi
    \ifdim\parshapeindent 2 = 3.0pt\else\bad\fi
    \ifdim\parshapedimen 4  = 4.0pt\else\bad\fi
    \ifdim\parshapedimen 5  = 5.0pt\else\bad\fi
    \ifdim\parshapedimen 6  = 6.0pt\else\bad\fi
    \ifdim\parshapedimen 7  = 5.0pt\else\bad\fi
    \ifdim\parshapedimen 0  = 0.0pt\else\bad\fi
    \parshape 0
    \ifdim\parshapedimen 1  = 0.0pt\else\bad\fi
:::

\\parsep (rubber length) {#cmd-parsep}
------------------------

The amount of vertical space between paragraphs within an item. It is
the value to which LaTeX sets `\parskip` within a list; unused by
*Tralics*.

\\parskip (rubber length) {#cmd-parskip}
-------------------------

You can say `\parskip=10pt plus 2pt minus 3pt`. This explains to TeX
that it should put 10pt (maybe up to 2pt more, maybe up to 3pt less) of
glue before the first lines of a paragraph. Unused by *Tralics*. (See
[scanglue](doc-s.html#fct-scanglue) for details of argument scanning).

\\part {#cmd-part}
------

The `\part` command is the highest division of a document. All
sectioning commands can be followed by an optional star, an optional
argument and a required argument. The translation is a `divXX` element
(where XX is replaced by a number), that contains the whole part,
chapter, section, or paragraph, and whose first element is the title
(translation of the mandatory argument) as a `<head>` element, and whose
second element is the alternatile title (translation of the optional
argument) as a `<alt_head>` element. In the starred case the element
will has the attribute `rend='nonumber'`. Otherwise, the counter is
incremented, and an anchor is created. In the example that follows the
anchor of the `\subparagraph` contains as id-text the value of
`\thesubparagraph`; the zero in this string is a consequence of the
section number not to be incremented. If the configuration file has
att_rend=\"Rend\" and att_nonumber=\"Nonumber\", you will see
`Rend='Nonumber'` instead. The translation of the following text

::: {.container .ltx-source}
    \part{A} \label{label-a}
    \chapter{B} \label{label-b}
    \section*[optc]{C} \label{label-c}
    \subsection{D} \label{label-d}
    \subsubsection{E} \label{label-e}
    \paragraph{F} \label{label-f}
    \subparagraph{G} \label{label-g}
    Text \par more text
    \ref{label-a} \ref{label-b} \ref{label-c}
    \ref{label-d} \ref{label-e} \ref{label-f} \ref{label-g}
:::

will be

::: {.container .xml_out}
    <div0 id-text='I' id='cid1'><head>A</head>
    <div1 id-text='1' id='uid1'><head>B</head>
    <div2 rend='nonumber'><head>C</head><alt_head>optc</alt_head>
    <div3 id-text='1.0.1' id='uid2'><head>D</head>
    <div4 id-text='1.0.1.1' id='uid3'><head>E</head>
    <div5 id-text='1.0.1.1.1' id='uid4'><head>F</head>
    <div6 id-text='1.0.1.1.1.1' id='uid5'><head>G</head>
    <p>Text </p>
    <p>more text
    <ref target='cid1'/> <ref target='uid1'/> <ref target='uid1'/>
    <ref target='uid2'/> <ref target='uid3'/> <ref target='uid4'/> <ref target='uid5'/>
    </p>
    ...
    </div6></div5></div4></div3></div2></div1></div0>
:::

The standard classes use a special command (see `` `\toplevelsection ``
\<doc-t.html\#cmd-toplevelsection\>[\_\_) for indicating the highest
division. Normally, there is no part nor chapter, so that
]{.title-ref}[part]{.title-ref}[, ]{.title-ref}[chapter]{.title-ref}[
and ]{.title-ref}[section]{.title-ref}[ give a
]{.title-ref}[\<div0\>]{.title-ref}[,
]{.title-ref}[subsection]{.title-ref}[ gives a
]{.title-ref}[\<div1\>]{.title-ref}[, etc. In the case of a report,
]{.title-ref}[part]{.title-ref}[ and ]{.title-ref}[chapter]{.title-ref}[
are the same, ]{.title-ref}[section]{.title-ref}[ is
]{.title-ref}[\<div1\>]{.title-ref}\`. In a book, all divisions are
different.

Whenever a division of level *k* is sensed, all divisions at the same
level and below (including `<p>`) are closed. In the case of a book, if
you say `\frontmatter`, `\mainmatter`, `\backmatter`, all divisions are
closed (these behave like an untitled part).

In the case of the article class, the previous example translates into
three `<div0>` elements, the first two one containing only a title. The
label c is in the third element. Since it is a starred section, it has
no anchor. In such a case the default anchor, namely uid1, is used. This
behavior might change in future versions.

The translation of the previous example could also be

::: {.container .xml_out}
    <div0 id-text='I' id='cid1'><head>A</head>
    </div0>
    <div0  id-text='1' id='cid2'><head>B</head>
    </div0>
    <div0 rend='nonumber'><head>C</head><alt_head>optc</alt_head>
    <div1 id-text='1.0.1' id='uid1'><head>D</head>
    <div2 id-text='1.0.1.1' id='uid2'><head>E</head>
    <div3 id-text='1.0.1.1.1' id='uid3'><head>F</head>
    <div4 id-text='1.0.1.1.1.1' id='uid4'><head>G</head>
    <p>Text </p>
    <p>more text
    <ref target='cid1'/> <ref target='cid2'/> <ref target='uid1'/>
    <ref target='uid1'/> <ref target='uid2'/> <ref target='uid3'/> <ref target='uid4'/>
    </p>
    ...
    </div4></div3></div2></div1></div0>
:::

\\partial (math symbol) {#cmd-partial}
-----------------------

The `\partial` command is valid only in math mode. It generates a
miscellaneous symbol: `<mi>&partial;</mi>` (Unicode U+2202, ∂). See
description of the `` `\ldots `` \<doc-l.html\#cmd-ldots\>\`\_\_
command.

participant, participante, participants, participantes (raweb environment) {#env-participant}
--------------------------------------------------------------------------

These four environments are defined by the ra package, included by the
raweb class files. By default all environments are identical, the
`participant` package option restores the default behavior (the XML
element name is the environment name).

::: {.container .ltx-source}
    \newenvironment{participants}{%
      \begin{xmlelement*}{participants}\let\par\empty\let\pers\persA}
      {\end{xmlelement*}\@addnl}
:::

These environments were designed for indicating people who participate
to the team\'s activity. They should contain only `\pers` commands
(syntax: first name, optional particle, last name, optional more-info).

::: {.container .ltx-source}
    \def\X{\pers{a}{b}} \def\Y{\pers{c}{d}}
    \begin{participant} \X\Y \end{participant}
    \begin{participante} \X\Y \end{participante}
    \begin{participants} \X\Y \end{participants}
    \begin{participantes} \X\Y \end{participantes}
:::

The translation is

::: {.container .xml_out}
    <participant>
     <pers prenom='a' nom='b'></pers>
     <pers prenom='c' nom='d'></pers>
    </participant>
    <participante>
     <pers prenom='a' nom='b'></pers>
     <pers prenom='c' nom='d'></pers>
    </participante>
    <participants>
     <pers prenom='a' nom='b'></pers>
     <pers prenom='c' nom='d'></pers>
    </participants>
    <participantes>
     <pers prenom='a' nom='b'></pers>
     <pers prenom='c' nom='d'></pers>
    </participantes>
:::

\\partopsep (rubber length) {#cmd-partopsep}
---------------------------

A list environment is surrounded by some glue in LaTeX, the sum of
`\topsep`, `\parskip` and optionally `\partopsep`. Nothing special is
done by *Tralics*.

\\patterns {#cmd-patterns}
----------

You can say something like
`\patterns{2'2 .a4 'a4 .\^a4 '\^a4 ab2h ... 1zi 1zo 1zu 1zy}` This
explains how to hyphenate all French words. Since *Tralics* does no
hyphenation, the command and its argument are ignored.

\\pausing (internal integer) {#cmd-pausing}
----------------------------

When you say `\pausing=89` (or any positive number) then TeX asks for
confirmation for every line of input. Unimplemented in *Tralics*, which
works essentially in batch mode. (See [scanint](doc-s.html#fct-scanint)
for details of argument scanning).

\\penalty (internal integer) {#cmd-penalty}
----------------------------

You can say `\penalty12345` in your document, but nothing special
happens (in vertical mode, TeX exercises the page builder). (see
[scanint](doc-s.html#fct-scanint) for how the argument is read).

\\perp (math symbol) {#cmd-perp}
--------------------

The `\perp` command is valid only in math mode. It generates a relation
symbol: `<mo>&perp;</mo>` (Unicode U+22A5, ⊥). See description of the
`` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\pers, \\persA, \\persB (Tralics command for the raweb) {#cmd-pers}
--------------------------------------------------------

**Warning:** These commands are not defined by *Tralics* but by the
raweb package; your mileage may vary. You say
`\pers {Don} {Knuth} [author of TeX]` inside a participant environment
and
`\pers {Donald} {Knuth} [Stanford] {Scientist} {American} [author of TeX]     [PHD]`
in the composition section. Brackets denote optional arguments. Between
the first to arguments, you can insert a particle like `[de]`. In such a
case, the particle is merged with the name that follows. A special hack
is applied: a footnote in the second argument is removed, and the
footnote text is moved to the optional argument (the one containing
\`author of TeX\'). Initial and final spaces are removed from the first
and last name. In the first case `\pers` is bound to `\persA`, and in
the second case it is `\persB`. Two auxiliary macros are involved
`\@persA` and `\@persB` that take three and seven arguments (the get the
arguments after merging the particle, and footnote hacking).

The `\persA` command takes two arguments, first name and last name, with
an optional argument between them (a particle), and an optional argument
after the name (info). Example

::: {.container .ltx-source}
    \begin{catperso}{List of Very Important Persons}
    % \makeatletter
    % \def\@persA#1#2#3{\xbox{pers}{\xbox{firstname}{#1}%
    %  \xbox{lastname}{#2}\xbox{info}{#3}}}
    \let\pers\persA
    \pers{Jean}[de la]{Fontaine}
    \pers{Donald}{Knuth}[author of \TeX]
    \pers{  Leslie  }{Lamport}
    \pers{Jose}{Grimm \footnote{No footnote here}}
    \end{catperso}
:::

This is the translation:

::: {.container .xml_out}
    <catperso><head>List of Very Important Persons 1</head>
    <pers prenom='Jean' nom='de la Fontaine'/>
    <pers prenom='Donald' nom='Knuth'>author of <TeX/></pers>
    <pers prenom='Leslie' nom='Lamport'/>
    <pers prenom='Jose' nom='Grimm'>No footnote here</pers>
    </catperso>
:::

If we uncomment the first few lines, we can change the presentation

::: {.container .xml_out}
    <catperso><head>List of Very Important Persons 1</head>
    <pers><firstname>Jean</firstname><lastname>de la Fontaine</lastname><info/>
    </pers><pers><firstname>Donald</firstname><lastname>Knuth</lastname>
      <info>author of <TeX/></info>
    </pers><pers><firstname>Leslie</firstname><lastname>Lamport</lastname><info/></pers
    ></catperso>
:::

In the section that describes the team, the `\pers` command is bound to
`\persB`. The syntax is:

-   a required argument, the first name of the person,
-   an optional argument, the particle,
-   a required argument, the last name of the person,
-   an optional argument, the effective research centre,
-   a required argument, the professional category of the person,
-   a required argument, the organization of the person,
-   an optional argument, the info field,
-   and an optional argument, the HDR flag.

Example
`\pers {Rose} {Dieng-Kuntz} [Sophia] {Scientist} {Inria} [1956-2008, Research Director] [yes]`.
The process is the same as for a normal `\persA`, there is some
preprocessing then the auxiliary macro is called. We show here the
preprocessing by redefining the auxiliary macro.

::: {.container .ltx-source}
    \begin{catperso}{List of Very Important Persons 2}
    \makeatletter
    \renewcommand\@persB[7][]{\xbox{pers}{\xbox{firstname}{#2}\xbox{lastname}{#3}%
    \xbox{localisation}{#1}\xbox{main-interest}{#4}\xbox{nationality}{#5}%
    \xbox{info}{#6}\xbox{hdr}{#7}}\@addnl}
    \pers{Jean}[de la]{Fontaine}{Tales}{French}[][phd]
    \pers{Donald}{Knuth}{Math}{American}[ author of \TeX]
    \pers{Leslie}{Lamport }{Computer Science}{American}
    \pers{Jose}{Grimm \footnote{No footnote here}}[Sophia]{Inria}{French}[funny text
    \end{catperso}
:::

Translation

::: {.container .xml_out}
    <catperso><head>List of Very Important Persons 2</head>
    <pers><firstname>Jean</firstname><lastname>de la Fontaine</lastname>
       <localisation/><main-interest>Tales</main-interest>
       <nationality>French</nationality><info/><hdr>phd</hdr>
    </pers>
    <pers><firstname>Donald</firstname><lastname>Knuth</lastname>
       <localisation/><main-interest>Math</main-interest>
       <nationality>American</nationality><info>author of <TeX/></info><hdr/>
    </pers>
    <pers><firstname>Leslie</firstname><lastname>Lamport</lastname>
       <localisation/><main-interest>Computer Science</main-interest>
       <nationality>American</nationality><info/><hdr/>
    </pers>
    <pers><firstname>Jose</firstname><lastname>Grimm</lastname>
      <localisation>Sophia</localisation><main-interest>Inria</main-interest>
      <nationality>French</nationality><info>No footnote here, funny text</info>
      <hdr/>
    </pers>
    </catperso>
:::

The command `\persB` checks the three optional parameters (localisation,
affiliation, and profession). See
[\\tralics\@find\@config](doc-t.html#cmd-tralicsfindconfig) for how the
macro can extract information from the configuration file. For instance,
if the configuration file contains a line of the form affiliation_vals
=\"Inria//Cnrs//University//\", then only Inria, Cnrs and University can
be used. The same holds for the profession, and research centers (the
list of valid fields for the Raweb is given on the Web page of the
Raweb). If *Tralics* is translating the activity report, a list of
research centres is given at the start of the document as in
`\UR{Sophia, Rocquencourt}`. For each person you have to indicate which
center it belongs to, this must be an element of the argument of `\UR`
(you can omit the argument in case the list has a single element).
Otherwise, an error is signaled. Note: there may be special cases: if
the argument is `+Rennes`, it will be replaced by `Rennes` and the check
is omitted, if the argument is `=Sophia`, this will provide a default
value for remaining persons. Example:

::: {.container .ltx-source}
    \pers {Jean B}{Dupond}[Lyon]{these}{Dec}[Ok][not yet]
    \pers {Jean A}{Dupond}[Sophia]{Chercheur}{CNRS}[Ok][not yet]
    \pers {Jean B}{Dupond}[+Lyon]{Ingenieur}{INRIA}[Ok][not yet]
    \pers {Jean C}{Dupond}[=Paris]{Other}{IBM}[Ok]
    \pers {Jean D}{Dupond}{Enseignant}{Other}[Ok][not yet]
:::

The translation is the following

::: {.container .xml_out}
    <pers prenom='Jean B' nom='Dupond' affiliation='Dec' profession='these' 
       hdr='not yet' research-centre='Lyon'>Ok</pers>
    <pers prenom='Jean A' nom='Dupond' affiliation='CNRS' profession='Chercheur'
       hdr='not yet' research-centre='Sophia'>Ok</pers>
    <pers prenom='Jean B' nom='Dupond' affiliation='INRIA' profession='Ingenieur' 
       hdr='not yet' research-centre='+Lyon'>Ok</pers>
    <pers prenom='Jean C' nom='Dupond' affiliation='IBM' profession='Other' 
       research-centre='=Paris'>Ok</pers>
    <pers prenom='Jean D' nom='Dupond' affiliation='Other' profession='Enseignant' 
       hdr='not yet'>Ok</pers>
:::

\\phantom {#cmd-phantom}
---------

See `` `\hphantom `` \<doc-h.html\#cmd-hphantom\>\`\_\_.

\\phi (math symbol) {#cmd-phi}
-------------------

The `\phi` command is valid only in math mode. It generates a Greek
letter: `<mi>&phiv;</mi>` (Unicode U+3D5, ϕ). See description of the
`` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\Phi (math symbol) {#cmd-cphi}
-------------------

The `\Phi` command is valid only in math mode. It generates an uppercase
Greek letter: `<mi>&Phi;</mi>` (Unicode U+3A6, Φ). See description of
the `` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\pi (math symbol) {#cmd-pi}
------------------

The `\pi` command is valid only in math mode. It generates a Greek
letter: `<mi>&pi;</mi>` (Unicode U+3C0, π). See description of the
`` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\Pi (math symbol) {#cmd-cpi}
------------------

The `\Pi` command is valid only in math mode. It generates an uppercase
Greek letter: `<mi>&Pi;</mi>` (Unicode U+3A0, Π). See description of the
`` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

picture (environment) {#env-picture}
---------------------

The translation of the `picture` environment is a `<picture>` element.
In it, you can put special objects, described in Chapter 7.1 of [the
LaTeX manual](index.html#latexbook'). It takes as argument a pair of
coordinates (for instance `(100,200)`) and a second one that is
optional.

Pair of coordinates are converted to dimensions, in the following way:
First, tokens are scanned until finding a comma, and then a closing
parenthesis. Standard catcodes are in use, and the characters should not
be hidden by braces. For instance `(10{,}2,3)` is a pair of coordinates,
the first one is `10{,}2`, the second is `3`. In the case of
`({12,3},456)`, the first is `12,3`, the second is `456` (note how
braces disappear). After that, `\unitlength` is pushed back, as well as
the token list, and [scandimen](doc-s.html#fct-scandimen) is called.
Note that token are expanded, but braces are not removed. Hence
`(10{,}2,3)` will provoke an error, and `({1,5},2)` is OK (since
`1,5\unitlength` means one and a half times `\unitlength`).

It is wise to set the value of `\unitlength` before the environment, and
to not modify it (but *Tralics* always uses the current value). See
`` `\unitlength `` \<doc-u.html\#cmd-unitlength\>\`\_\_ command.

| There are commands, like `\line`, that take as argument a pair of
  integers, interpreted by [scanint](doc-s.html#fct-scanint). For
  instance, `\line(0,\parindent){25}` is syntactically correct.
| ![See\...](/img/AR.png) For examples, see the `` `\qbezier ``
  \<doc-q.html\#cmd-qbezier\>[\_\_ command, and the ]{.title-ref}`\arc`
  \<doc-a.html\#cmd-arc\>\`\_\_ command.

\\pitchfork (math symbol) {#cmd-pitchfork}
-------------------------

The `\pitchfork` command is valid only in math mode. It generates
`<mi>&pitchfork;</mi>` (Unicode U+22D4, ⋔).

\\\@plus {#cmd-plus}
--------

This command expands to `plus`. Do not modify it.

\\pm (math symbol) {#cmd-pm}
------------------

The `\pm` command is valid only in math mode. It generates a binary
operator: `<mo>&pm;</mo>` (Unicode U+B1, ±). *Tralics* recognizes the
following binary operators:

::: {.container .ltx-source}
:

    $ \pm \mp \times \div \ast \star \circ \bullet \cdot 
    \cap \cup \uplus \sqcap \sqcup \vee \wedge \setminus \wr
    \diamond \bigtriangleup \bigtriangledown \triangleleft \triangleright
    \oplus \ominus \otimes \oslash \odot \bigcirc \dagger \ddagger \amalg$
:::

The XML result is

::: {.container .xml_out}
    <formula type='inline'><math xmlns='http://www.w3.org/1998/Math/MathML'>
    <mrow><mo>&pm;</mo><mo>&mp;</mo> <mo>&times;</mo> <mo>&div;</mo> <mo>&ast;</mo> 
    <mo>&star;</mo> <mo>&SmallCircle;</mo> <mo>&bullet;</mo> <mo>&middot;</mo> 
    <mo>&cap;</mo> <mo>&cup;</mo> <mo>&uplus;</mo> <mo>&sqcap;</mo> 
    <mo>&sqcup;</mo> <mo>&vee;</mo> <mo>&wedge;</mo> <mo>&setminus;</mo> 
    <mo>&wr;</mo> <mo>&diamond;</mo> <mo>&bigtriangleup;</mo> <mo>&bigtriangledown;</mo> 
    <mo>&triangleleft;</mo> <mo>&triangleright;</mo> <mo>&oplus;</mo> <mo>&ominus;</mo> 
    <mo>&otimes;</mo> <mo>&osol;</mo> <mo>&odot;</mo> <mo>&bigcirc;</mo> 
    <mo>&dagger;</mo> <mo>&ddagger;</mo> <mo>&amalg;</mo></mrow></math></formula>
:::

All these operators are from Table 8.4 of the [Latex
Companion](index.html#companion). If you do not like entity names, you
can use the -noentnames switch, and you get

::: {.container .xml_out}
    <formula type='inline'>
     <math xmlns='http://www.w3.org/1998/Math/MathML'>
      <mrow><mo>&#xB1;</mo><mo>&#x02213;</mo><mo>&#xD7;</mo><mo>&#xF7;</mo>
      <mo>&#x2A;</mo><mo>&#x02606;</mo><mo>&#x02218;</mo><mo>&#x02022;</mo>
      <mo>&#xB7;</mo><mo>&#x02229;</mo><mo>&#x0222A;</mo><mo>&#x0228E;</mo>
      <mo>&#x02293;</mo><mo>&#x02294;</mo><mo>&#x02228;</mo><mo>&#x02227;</mo>
      <mo>&#x02216;</mo><mo>&#x02240;</mo><mo>&#x022C4;</mo><mo>&#x025B3;</mo>
      <mo>&#x025BD;</mo><mo>&#x025C3;</mo><mo>&#x025B9;</mo><mo>&#x02295;</mo>
      <mo>&#x02296;</mo><mo>&#x02297;</mo><mo>&#x000F8;</mo><mo>&#x02299;</mo>
      <mo>&#x025EF;</mo><mo>&#x02020;</mo><mo>&#x02021;</mo><mo>&#x02A3F;</mo>
     </mrow></math>
    </formula>
:::

![binary operators from Table 8.4](/img/img_6.png)

\\pmod, \\pod {#cmd-pmod}
-------------

This is one of the four modulo commands. See `` `\bmod ``
\<doc-b.html\#cmd-bmod\>\`\_\_ for an example.

\\postdisplaypenalty (internal integer) {#cmd-postdisplaypenalty}
---------------------------------------

When you say `\postdisplaypenalty=97`, then TeX will use 97 as penalty
for a page break after a display formula. Unused by *Tralics*. (See
[scanint](doc-s.html#fct-scanint) for details of argument scanning).

\\pounds {#cmd-pounds}
--------

This is the same as `` `\textsterling ``
\<doc-t.html\#cmd-textsterling\>\`\_\_. It generates the pound sign £.

\\Pr (math symbol) {#cmd-Pr}
------------------

The `\Pr` command is valid only in math mode. Its translation is a math
operator of the same name `<mo form='prefix'>Pr</mo>`. For an example
see the `` `\log `` \<doc-l.html\#cmd-log\>\`\_\_ command.

\\prec (math symbol) {#cmd-prec}
--------------------

The `\prec` command is valid only in math mode. It generates a relation
symbol: `<mo>&prec;</mo>` (Unicode U+227A, ≺). See description of the
`` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\precapprox (math symbol) {#cmd-precapprox}
--------------------------

The `\precapprox` command is valid only in math mode. It generates a
relation symbol: `<mo>&precapprox;</mo>` (Unicode U+2AB7, ⪷).

\\preccurlyeq (math symbol) {#cmd-preccurlyeq}
---------------------------

The `\preccurlyeq` command is valid only in math mode. It generates a
relation symbol: `<mo>&preccurlyeq;</mo>` (Unicode U+227C, ≼).

\\preceq (math symbol) {#cmd-preceq}
----------------------

The `\preceq` command is valid only in math mode. It generates a
relation symbol: `<mo>&preceq;</mo>` (Unicode U+2AAF, ⪯).

\\precnapprox (math symbol) {#cmd-precnapprox}
---------------------------

The `\precnapprox` command is valid only in math mode. It generates a
relation symbol: `<mo>&precnapprox;</mo>` (Unicode U+2AB9, ⪹).

\\precneqq (math symbol) {#cmd-precneqq}
------------------------

The `\precneqq` command is valid only in math mode. It generates a
relation symbol: `<mo>&precneqq;</mo>` (Unicode U+2AB5, ⪵).

\\precnsim (math symbol) {#cmd-precnsim}
------------------------

The `\precnsim` command is valid only in math mode. It generates a
relation symbol: `<mo>&precnsim;</mo>` (Unicode U+22E8,⋨).

\\precsim (math symbol) {#cmd-precsim}
-----------------------

The `\precsim` command is valid only in math mode. It generates a
relation symbol: `<mo>&precsim;</mo>` (Unicode U+227E, ≾).

\\predisplaydirection (internal integer) {#cmd-predisplaydirection}
----------------------------------------

The integer `\predisplaydirection` contains the text direction preceding
a display. Not used by *Tralics*.

\\predisplaypenalty (internal integer) {#cmd-predisplaypenalty}
--------------------------------------

When you say `\predisplaypenalty=96`, then TeX will use 96 as penalty
for a page break before a display formula. Unused by *Tralics*. (See
[scanint](doc-s.html#fct-scanint) for details of argument scanning).

\\predisplaysize (rigid length) {#cmd-predisplaysize}
-------------------------------

You may say `\predisplaysize=5pt`, and the consequence is the following.
First, whenever TeX enters a display equation it sets itself
`\predisplaysize` to the length of the line that precedes the display
(or `-\maxdimen` in case this is irrelevant). The variable is consulted
after the display is finished (and your modifications are taken into
account). The variable `\displayindent` is set to some value (depending
on `\parshape`, etc.) before the display is typeset and read after; the
same holds for `\displaywidth` (this is the linelength).

After the math formula is typeset (converted to a box), it is added to
the main vertical list. Let *d* be half the line length
(`\displaywidth`) minus the width of the equation; adding a space of
width *d* before the formula will center it. If the formula is too big,
with respect to the equation number, some minor corrections are added
(see TeXbook, chapter 19 for all details). Let *d+s* be the sum of this
*d* and the value of `\displayindent`.

If *d+s* is less than `\predisplaysize`, or if there is a left equation
number, then a glue of value `\abovedisplayskip` is added before the
display, a glue of value `\belowdisplayskip` is added after the display;
otherwise `\abovedisplayshortskip` and `\belowdisplayshortskip` are
used.

| This parameter is ignored by *Tralics*.
| ![See\...](/img/AR.png) (See [scandimen](doc-s.html#fct-scandimen) for
  details of argument scanning).

\\presetkeys {#cmd-presetkeys}
------------

This command is provided by the [xkeyval](doc-k.html#cmd-keyval)
package.

\\pretolerance (internal integer) {#cmd-pretolerance}
---------------------------------

| If you say `\pretolerance=25`, the first pass of TeX\'s line breaking
  algorithm succeeds if no line has a badness exceeding 25 (if the
  pretolerance is negative, TeX omits the first pass). This is not used
  by *Tralics*, because no line breaking algorithm is defined. But
  `\pretolerance` is set equal to 100.
| ![See\...](/img/AR.png) (See [scanint](doc-s.html#fct-scanint) for
  details of argument scanning).

\\prevdepth {#cmd-prevdepth}
-----------

TeX has an internal variable, named *aux* that contains, in horizontal
mode, the `\spacefactor` and current language. In vertical mode, the
*aux* variable contains the `\prevdepth`; it is the scaled value
representing the depth of the previous box, for use in baseline
calculations, or it is \<=-1000pt if the next box on the vertical list
is to be exempted from baseline calculations.

In *Tralics*, paragraphs are not split into lines, no baseline
computations are done, and this quantity is useless. You can say
`\prevdepth=123pt`, and nothing happens. As a consequence,
`\showthe \prevdepth` will always print 0.0pt.

\\prevgraf {#cmd-prevgraf}
----------

TeX has an internal variable called `\prevgraf` that records the number
of lines in the most recent paragraph that has been completed or
partially completed. The value of this variable is used by the line
breaking algorithm only when TeX is dealing with nonstandard `\parshape`
or `\hangindent`. The value of `\displaywidth` and `\displayindent` can
also depend on the value of `\prevgraf`. A displayed equation, whatever
its value, adds three to `\prevgraf`.

Since *Tralics* does not convert paragraphs into lines, it does not
compute this quantity, and does not use it. If you say `\prevgraf=15`
nothing happens. If say `\showthe \prevgraf` you will get 0.

\\Prime (math symbol) {#cmd-cprime}
---------------------

The `\Prime` command is valid only in math mode. It generates the double
prime character `<mo>&Prime;</mo>` (Unicode U+2033, ″).

\\prime (math symbol) {#cmd-prime}
---------------------

The `\prime` command is valid only in math mode. It generates the single
prime character `<mo>&apos;</mo>` (Unicode U+27). See description of the
`` `\ldots `` \<doc-l.html\#cmd-ldots\>\`\_\_ command.

\\printindex, \\printglossary {#cmd-printindex}
-----------------------------

These commands define the place where to put the index or glossary, if
omitted the end of the document will be used. For details see see
[\\index](doc-i.html#indexplus).

\\prod (math symbol) {#cmd-prod}
--------------------

The `\prod` command is valid only in math mode. Its translation is a
variable-sized symbol: `<mo>&prod;</mo>`(Unicode U+220F; ∏). For an
example see the `` `\sum `` \<doc-s.html\#cmd-sum\>\`\_\_ command.

\\ProcessOptions, \\ProcessOptionsX {#cmd-processoptions}
-----------------------------------

| Let\'s consider a package (or class file) that defines options A, B, C
  and D, and is loaded with C, A and E. If you say `\ProcessOptions*`,
  the following happens: the code of options C and A is executed. If the
  optional star is omitted, the code of A and C is executed (the
  execution order is specified by the class file; in the case of a star,
  the order is given by the user file). A warning is signalled if you
  use a package option, like E, that is not defined by the package. On
  the other hand, a class option becomes a global option. This option is
  visible by every package (a warning is signaled by the
  `\begin{document}` command if no package declares the option).
| ![See\...](/img/AR.png) See `` `\DeclareOption ``
  \<doc-d.html\#cmd-DeclareOption\>[\_\_ for how to declare an option.
  The xkeyval package provides
  ]{.title-ref}[ProcessOptionsX]{.title-ref}[ (see \`xkeyval
  \<doc-k.html\#cmd-keyval\>]{.title-ref}\_\_). In the current version,
  global class options are not available.

\\projlim (math symbol) {#cmd-projlim}
-----------------------

| The `\projlim` command is valid only in math mode. Its translation is
  a math operator of the same name
  `<mo form='prefix' movablelimits='true'>projlim</mo>`.
| ![See\...](/img/AR.png) For an example see the `` `\log ``
  \<doc-l.html\#cmd-log\>\`\_\_ command.

\\propto (math symbol) {#cmd-propto}
----------------------

The `\propto` command is valid only in math mode. It generates a
relation symbol: `<mo>&propto;</mo>` (Unicode U+221D, ∝). See
description of the `` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\protect {#cmd-protect}
---------

The `\protect` command can be used to delay expansion of a command.
Normally, its value is `\relax`, but is can be `\string` (so that
`\protect\foo` prints like `\foo`) or `\noexpand\protect\noexpand`, so
that `\protect\foo` expands to `\protect\foo` (this is useful in an
`\edef`).

In *Tralics*, the `\protect` command cannot be expanded, it translates
to nothing.

\\protected (eTeX extension) {#cmd-protected}
----------------------------

The command `\protected` is a prefix, like `\long`, that applies to a
macro definition. A protected macro is not expanded when building an
expanded token list (for instance in `\edef`).

\\provideboolean {#cmd-provideboolean}
----------------

| If you say `\provideboolean{foo}`, the effect is the the same as
  `\newboolean{foo}`: it defines `\iffoo`. However, nothing happens if
  `\iffoo` exists (we assume that this command was defined by
  `\newboolean`, and not by a random `\newcommand`. The control sequence
  `\iffoo` is created by `` `\csname ``
  \<doc-c.html\#cmd-csname\>\`\_\_, nasty errors may occur).
| ![See\...](/img/AR.png) See `` `\newboolean ``
  \<doc-n.html\#cmd-newboolean\>\`\_\_ for how to use booleans.

\\providecommand {#cmd-providecommand}
----------------

The `\providecommand` is like `` `\newcommand ``
\<doc-n.html\#cmd-newcommand\>\`\_\_. It has the same syntax, it defines
a command, but if the command is already defined, no error is signaled,
and the command is left unchanged.

\\ProvidesClass, \\ProvidesFile, \\ProvidesPackage {#cmd-providesclass}
--------------------------------------------------

The three commands `\ProvidesFile`, `\ProvidesClass` and
`\ProvidesPackage` have a similar syntax (see below), a required
argument, that should be a file name, and an optional argument, that
starts with a date, and is generally followed by a version number and a
small comment. The argument is printed on the transcript file. The two
commands `\ProvidesClass` and `\ProvidesPackage` should be used in class
or package file. The command checks that the argument is the same as the
file name; in the example below, we have renamed RR.plt as foo.plt,
there is a mismatch on the name. Moreover, at the end of the package, a
check is made to see if the package is up to date, by comparing the date
arguments.

::: {.container .tty_out}
    % package
    \ProvidesPackage{RR}[2007/04/25 v1.3 Inria RR for Tralics]
    % tex file 
    \usepackage[bar]{foo}[2008/01/01]
    % tty
    Warning: package foo claims to be RR.
    Unknown option `bar' for package `foo'
    Warning: You have requested, on line 3, version
    `2008/01/01' of package foo,
    but only version
    `2007/04/25 v1.3 Inria RR for Tralics' is available
:::

\\psi (math symbol) {#cmd-psi}
-------------------

The `\psi` command is valid only in math mode. It generates a Greek
letter:`<mi>&psi;</mi>` (Unicode U+3C8, ψ). See description of the
`` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\Psi (math symbol) {#cmd-cpsi}
-------------------

The `\Psi` command is valid only in math mode. It generates an uppercase
Greek letter: `<mi>&Psi;</mi>` (Unicode U+3A8, Ψ). See description of
the `` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\psfig {#cmd-psfig}
-------

Instead of saying `\psfig{file=x,width=1}` you should say
`\includegraphics [width=1] {x}`. See `` `\includegraphics ``
\<doc-i.html\#cmd-includegraphics\>\`\_\_ command.

\\put {#cmd-put}
-----

You say `\put(x,y){object}` in order to put an object at a given
position into a picture. See description of the `` `picture ``
\<doc-p.html\#env-picture\>[\_\_ environment for the syntax of the
]{.title-ref}[(x,y)]{.title-ref}\` part, and some examples.
