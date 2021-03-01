All commands, alphabetic order; letter N
========================================

This page contains the description of [\\\@ne](doc-o.html#cmd-one),
[\\nabla](#cmd-nabla), [\\\@namedef](#cmd-namedef),
[\\\@nameuse](#cmd-nameuse), [\\natcite](doc-c.html#cmd-cite),
[\\natural](#cmd-natural), [\\ncong](#cmd-ncong),
[\\nearrow](#cmd-nearrow), [\\ne](#cmd-ne),
[\\NeedsTeXFormat](#cmd-needsformat), [\\neg](#cmd-neg),
[\\neq](#cmd-neq), [\\newblock](#cmd-newblock),
[\\newboolean](#cmd-newboolean), [\\newbox](#cmd-newbox),
[\\newcolumntype](#cmd-newcolumntype), [\\newcommand](#cmd-newcommand),
[\\newcount](#cmd-newcount), [\\newcounter](#cmd-newcounter),
[\\newdimen](#cmd-newdimen), [\\newenvironment](#cmd-newenvironment),
[\\newfont](#cmd-newfont), [\\newif](#cmd-newif),
[\\newindex](#cmd-newindex), [\\\@newindex](#cmd-newindex),
[\\newlength](#cmd-newlength), [\\newlanguage](#cmd-newlanguage),
[\\newline](#cmd-newline), [\\newlinechar](#cmd-newlinechar),
[\\newsmukip](#cmd-newmuskip), [\\newpage](#cmd-newpage),
[\\newread](#cmd-newread), [\\newsavebox](#cmd-newsavebox),
[\\newskip](#cmd-newskip), [\\newtoks](#cmd-newtoks),
[\\newtheorem](#cmd-newtheorem), [\\newwrite](#cmd-newwrite),
[\\nexists](#cmd-nexists), [\\ng](#cmd-ng), [\\ngeq](#cmd-ngeq),
[\\ngtr](#cmd-ngtr), [\\NG](#cmd-cng), [\\ni](#cmd-ni),
[\\\@nil](doc-c.html#cmd-car), [\\niplus](#cmd-niplus),
[\\\@nnil](doc-c.html#cmd-car), [\\nleftarrow](#cmd-nleftarrow),
[\\nLeftarrow](#cmd-cnleftarrow),
[\\nLeftrightarrow](#cmd-cnleftrightarrow),
[\\nleftrightarrow](#cmd-nleftrightarrow), [\\nleq](#cmd-nleq),
[\\nless](#cmd-nless), [\\nmid](#cmd-nmid), [\\no](#cmd-numero),
[\\No](#cmd-cnumero), [\\noalign](#cmd-noalign),
[\\noboundary](#cmd-noboundary), [\\nobreak](#cmd-nobreak),
[\\nobreakspace](#cmd-nobreakspace), [\\nocentering](#cmd-nocentering),
[\\nocite](#cmd-nocite), [\\node](#cmd-node), [\\nodebox](#cmd-nodebox),
[\\nodecircle](#cmd-nodecircle), [\\nodeconnect](#cmd-nodeconnect),
[\\nodecurve](#cmd-nodecurve), [\\nodeoval](#cmd-nodeoval),
[\\nodepoint](#cmd-nodepoint), [\\nodetriangle](#cmd-nodetriangle),
[\\noexpand](#cmd-noexpand),
[\\nonfrenchspacing](#cmd-nonfrenchspacing),
[\\noindent](#cmd-noindent), [\\nointerlineskip](#cmd-nointerlineskip),
[\\nolimits](#cmd-nolimits), [\\nolinebreak](#cmd-nolinebreak),
[\\\@nomathml](#cmd-nomathml), [\\\@nomathswi](#cmd-nomathsw),
[\\\@nomathswii](#cmd-nomathsw), [\\nonscript](#cmd-nonscript),
[\\nonstopmode](#cmd-nonstopmode), [\\nonumber](#cmd-nonumber),
[\\noopsort](#cmd-noopsort), [\\nopagebreak](#cmd-nopagebreak),
[\\normalbaselines](#cmd-normalbaselines),
[\\normalbaselineskip](#cmd-normalbaselineskip),
[\\normalcolor](#cmd-normalcolor), [\\normalfont](#cmd-normalfont),
[\\normallineskip](#cmd-normallineskip),
[\\normallineskiplimit](#cmd-normallineskiplimit),
[\\normalmarginpar](doc-m.html#cmd-marginpar),
[\\normalsize](#cmd-normalsize), [\\not](#cmd-not), [\\NOT](#cmd-cnot),
[\\notag](#cmd-notag), [\\notin](#cmd-notin),
[\\\@notprerr](#cmd-notprerr), [\\notrivialmath](#cmd-notrivialmath),
[\\nparallel](#cmd-nparallel), [\\nprec](#cmd-nprec),
[\\nRightarrow](#cmd-cnrightarrow), [\\nrightarrow](#cmd-nrightarrow),
[\\nsim](#cmd-nsim), [\\nsubseteq](#cmd-nsubseteq),
[\\nsucc](#cmd-nsucc), [\\nsupseteq](#cmd-nsupseteq),
[\\ntriangleleft](#cmd-ntriangleleft),
[\\ntrianglelefteq](#cmd-ntrianglelefteq),
[\\ntrianglelefteqslant](#cmd-ntrianglelefteqslant),
[\\ntriangleright](#cmd-ntriangleright),
[\\ntrianglerighteq](#cmd-ntrianglerighteq),
[\\ntrianglerighteqslant](#cmd-ntrianglerighteqslant), [\\nu](#cmd-nu),
[\\null](#cmd-null), [\\nulldelimiterspace](#cmd-nulldelimiterspace),
[\\nullfont](#cmd-nullfont), [\\number](#cmd-number),
[\\numberedverbatim](#cmd-numberedverbatim),
[\\numberwithin](#cmd-numberwithin), [\\numero](#cmd-numero),
[\\Numero](#cmd-cnumero), [\\numexpr](#cmd-numexpr), [\\nvdash,
\\nvDash, \\nVdash, \\nVDash](#cmd-nvdash), [\\nwarrow](#cmd-nwarrow).

------------------------------------------------------------------------

\\nabla (math symbol) {#cmd-nabla}
---------------------

The `\nabla` command is valid only in math mode. It generates a
miscellaneous symbol: `<mi>&nabla;</mi>` (Unicode U+2207, ∇). See
description of the `` `\ldots `` \<doc-l.html\#cmd-ldots\>\`\_\_
command.

\\\@namedef {#cmd-namedef}
-----------

Instead of `\expandafter\def\csname xxx\endcsname ...` you can say
`\@namedef{xxx}...`. The result is the same.

\\\@nameuse {#cmd-nameuse}
-----------

Instead of `\csname xxx\endcsname` you can say `\@nameuse{xxx}`. For
instance, if you have two counters A and B, and you want that A prints
in the same way as B, more precisely, you want `\theA` to call `\theB`,
you say `\Test{A}{B}`, after the following definition:
`\def\Test#1#2{\global \@namedef {the#1}{\@nameuse {the#2}}}`.

\\natural (math symbol) {#cmd-natural}
-----------------------

The `\natural` command is valid in math mode and text mode. It generates
a miscellaneous symbol: `<mo>&natur;</mo>` (Unicode U+266E, ♮). See
description of the `` `\qquad `` \<doc-q.html\#cmd-qquad\>[\_\_ and
]{.title-ref}`\ldots` \<doc-l.html\#cmd-ldots\>\`\_\_ commands.

\\ncong (math symbol) {#cmd-ncong}
---------------------

The `\ncong` command is valid only in math mode. It generates:
`<mo>&2247;</mo>`, ≇.

\\ne (math symbol) {#cmd-ne}
------------------

The `\ne` command is valid only in math mode. It generates a relation
symbol: `<mo>&ne;</mo>` (Unicode U+2260, ≠). See description of the
`` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\nearrow (math symbol) {#cmd-nearrow}
-----------------------

The `\nearrow` command is valid only in math mode. It generates an arrow
that points North-East: `<mo>&nearrow;</mo>` (Unicode U+2197, ↗). See
description of the `` `\leftarrow `` \<doc-l.html\#cmd-leftarrow\>\`\_\_
command.

\\NeedsTeXFormat {#cmd-needsformat}
----------------

A typical class file contains a declaration like
`\NeedsTeXFormat{LaTeX2e}[1995/12/01]`. This is ignored by *Tralics*.

\\neg (math symbol) {#cmd-neg}
-------------------

| The `\neg` command is valid only in math mode. It generates a
  miscellaneous symbol (character ¬).
| ![See\...](/img/AR.png) See description of the `` `\ldots ``
  \<doc-l.html\#cmd-ldots\>\`\_\_ command.

\\neq (math symbol) {#cmd-neq}
-------------------

The `\neq` command is valid only in math mode. It is the same as `\ne`.
It generates a relation symbol: `<mo>&ne;</mo>` (Unicode U+2260, ≠). See
description of the `` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\newblock {#cmd-newblock}
----------

This command expands to `\hskip .11em plus.33em minus.07em`.

\\newboolean {#cmd-newboolean}
------------

| You can say `\newboolean{foo}`, this is the same as `\newif\iffoo`.
  However, an error is signaled if `\iffoo` already exists. The control
  sequence `\iffoo` is created by `` `\csname ``
  \<doc-c.html\#cmd-csname\>[\_\_, nasty errors may occur. The boolean
  value of foo can be changed by
  ]{.title-ref}[setboolean{foo}]{.title-ref}[ (rather than by
  ]{.title-ref}[footrue]{.title-ref}[ or
  ]{.title-ref}[foofalse]{.title-ref}[). It can be tested via
  ]{.title-ref}[boolean]{.title-ref}\`.
| ![See\...](/img/AR.png) (see description of `\ifthenelse`) (also see
  `` `\newif `` \<doc-n.html\#cmd-newif\>\`\_\_) for some details).

Example (translation is `oka okb`)

::: {.container .ltx-source}
    { %The command \bad is not executed here 
    \def\double#1{#1#1}
    \newboolean{f\double o}
    \def\swap{\setboolean{f\double o}{\iffoo fals \else TRU\fi e}}
    \ifthenelse{\boolean{foo}}{\bad}{oka}
    \swap 
    \ifthenelse{\boolean{foo}}{okb}{\bad}
    }
:::

\\newbox {#cmd-newbox}
--------

The `\newbox` command is similar in principle to `` `\newcount ``
\<doc-n.html\#cmd-newcount\>[\_\_. After
]{.title-ref}[newboxfoo]{.title-ref}[, the
]{.title-ref}[foo]{.title-ref}[ commands refers to some box, and each
call to ]{.title-ref}[newbox]{.title-ref}[ produces a reference to a
different box. You say ]{.title-ref}[setboxfoo =
hbox{\...}]{.title-ref}[ if you want to put something in the box,
]{.title-ref}[boxfoo]{.title-ref}[ or
]{.title-ref}[copyfoo]{.title-ref}[ if you want to use the box or its
copy. Note: ]{.title-ref}[foo]{.title-ref}\` is, in reality, a reference
to a character. (Lamport calls it a "bin").

\\newcolumntype {#cmd-newcolumntype}
---------------

| The `\newcolumntype` command can be used to define a new column type
  (in addition to flush left, flush right and center).
| ![See\...](/img/AR.png) See documentation on [arrays](doc-array.html).

\\newcommand {#cmd-newcommand}
------------

The LaTeX way of defining commands is via `\newcommand`. Here are some
examples

::: {.container .ltx-source}
    \newcommand*\NCA{nca}
    \newcommand{\NCB}[0]{ncb}
    \newcommand{\NCC}[2]{ncc#1#2}
    \newcommand{\NCD}[2][x]{ncd#1#2}
    \NCA and \NCB and \NCC{arg1}{arg2} and 
    \NCD[arg1]{arg2} and \NCD{arg2}
:::

The argument of `\newcommand` should be a single token (`\cmd25` is
wrong), a command name (or an active character) that is undefined. It is
followed by the number of arguments (in brackets, default is zero, only
explicit digits are allowed), followed by an optional argument in
brackets, followed by a command body. In the body, `#1` refers to the
first argument, `#2` to the second, etc (you cannot use `#7` if the
command does not take at least seven arguments).

In the case of a command like `\NCD`, the number of arguments should be
at least one. When you say `\NCC{y}`, then `y` is the second argument
(and the first argument takes its default value, here `x`). When you say
`\NCD[1]{2}`, the first argument is `1`, the second argument is `2`. The
commands are `\long` (they accept `\par` in their arguments), unless
`\newcommand*` is used ( You can put an optional `*` after
`\newcommand`, (it means non-`\long` in LaTeX).

\\newcount {#cmd-newcount}
----------

This command allocates a new counter register and defines a macro that
references it.

There are N=256 count registers, indexed by a number between 0 and N-1,
for instance `\count0`, or `\count23`. (In current versions of
*Tralics*, N is 1024). It is sometimes wise to give a symbolic name to a
counter. For instance, `\countdef\foo 25` makes `\foo` a reference to
`\count25`. On the other hand, it is more efficient to say `\foo` than
`\count25`, (because it avoids a call to
[scanint](doc-s.html#fct-scanint)) and `\foo3` is not the same as
`\count253`.

| There is a mechanism that makes sure that a register is not used more
  than once: the `\newcount` command uses a different number each time,
  first 20, then 21, then 22, etc. Numbers less than 10 are not
  allocated. Numbers between 10 and 19 are used by the new-something
  mechanism. When you say `\newcount\foo`, a counter is allocated, and
  `\foo` is made a reference to it. Then `\foo=3` puts 3 in the counter,
  `\advance\foo by 1` increments the counter, and `\the\foo` typesets
  the counter. Allocation is always global.
| ![See\...](/img/AR.png) See `` `\loop `` \<doc-loop.html\>\`\_\_ for
  an example.

\\newcounter {#cmd-newcounter}
------------

The `\newcounter` command is similar in principle to `` `\newcount ``
\<doc-n.html\#cmd-newcount\>[\_\_. However, LaTeX adds additional
features. When you say ]{.title-ref}[newcounterfoo]{.title-ref}[, a
number is allocated, say 25, and the command
]{.title-ref}[c\@foo]{.title-ref}[ is made equivalent to
]{.title-ref}[count25]{.title-ref}[. See for instance \`description of
counters \<doc-c.html\#counter\>]{.title-ref}\_\_. The expression
`\value{foo}` expands to `\c@foo`, hence to `\count25`. This means that
`\value{foo}=12` is one way to set the value to 12, but you should say
`\setcounter{foo}{12}`. This sets the value to 12, globally. You can
also say `\addtocounter{foo}{25}`, if you want to add (globally) 25 to
the value of the counter.

You can say `\number\value{foo}` if you want to typeset the number, and
even `\the\value{foo}`. If fact, you say `\arabic{foo}` if you want an
arabic version (you can use `\roman`, `\alph` etc). You say `\thefoo`
when you want to typeset the counter foo and what is related (default
value is arabic, but you can say `\renewcommand \thefoo {\roman{foo}}`).
You can say:
`\renewcommand \thesection {\thechapter .\arabic{section}}`. Then
`\thesection` typesets `\thechapter`, a dot, and the section counter as
an arabic number.

When you say `\newcounter {section}[chapter]`, this modifies a property
of the chapter counter (in fact the `\cl@chapter` command), so that,
whenever it is incremented by `\stepcounter`, the section counter is
reset to zero. Example

::: {.container .ltx-source}
    { 
      \newcounter{toto}
      \newcounter{titi}[toto]
      \newcounter{tata}[titi]
      \newcounter{tutu}[toto]

      \setcounter{toto}{10}
      \setcounter{titi}{20}
      \setcounter{tata}{30}
      \setcounter{tutu}{40}
    \expandafter\show\value{toto}\expandafter\showthe\value{toto}
    \expandafter\show\value{titi}\expandafter\showthe\value{titi}
    \expandafter\show\value{tata}\expandafter\showthe\value{tata}
    \expandafter\show\value{tutu}\expandafter\showthe\value{tutu}
      \stepcounter{toto} %  kills titi, tutu
      \stepcounter{tata}\thetata=31, 
      \stepcounter{titi}\thetata=0 % titi=1
      \stepcounter{tutu} 
      \thetoto\thetiti\thetata\thetutu=11101

    \makeatletter
    \show\cl@toto
    \show\cl@titi
    \show\cl@tata
    \show\cl@tutu
    }%
:::

Translation is: 31=31, 0=0 11101=11101. *Tralics* prints the following.
Note that `\c@toto` is a pointer into an internal table that contains
catcodes, lccodes, etc. \[In old version of Tralics, `\show\c@toto` gave
`\countref1536`, because the counter is at position 1536 if the integer
part of eqtb table\].

::: {.container .tty_out}
    \c@toto=\count26.
    \show: 10
    \c@titi=\count27.
    \show: 20
    \c@tata=\count28.
    \show: 30
    \c@tutu=\count29.
    \show: 40
    \cl@toto=macro: ->\@elt {titi}\@elt {tutu}.
    \cl@titi=macro: ->\@elt {tata}.
    \cl@tata=macro: ->.
    \cl@tutu=macro: ->.
:::

\\newdimen {#cmd-newdimen}
----------

| The `\newdimen` command is similar in principle to `` `\newcount ``
  \<doc-n.html\#cmd-newcount\>[\_\_. When you say
  ]{.title-ref}[newdimenfoo]{.title-ref}[, then
  ]{.title-ref}[foo]{.title-ref}[ is a reference to one of the N
  dimension registers. You can use ]{.title-ref}[foo]{.title-ref}[ in
  the same way as ]{.title-ref}[dimen0]{.title-ref}[. For instance
  ]{.title-ref}[foo=25pt]{.title-ref}[ will set the dimension to 25pt.
  It is the same as ]{.title-ref}[setlength{foo}{25pt}]{.title-ref}[.
  You can say ]{.title-ref}[advancefoo by 3pt]{.title-ref}[ if you want
  to increase the value, or you can say
  ]{.title-ref}[addtolength{foo}{3pt}]{.title-ref}\`.
| In TeX N=256, in the current version of *Tralics* it is 1024.

\\newenvironment {#cmd-newenvironment}
----------------

An environment, like `foo` is defined by two commands `\foo` and
`\endfoo`. It is defined by the `\newenvironment` command, that takes as
argument a name (*Tralics* accepts only characters); the command
associated to this name should not be already defined.

For instance, `\newenvironment{foo} {xxx} {yyy}` is like
`\newcommand{\foo}{xxx}`, `\def\endfoo{yyy}`. Said otherwise, the `\foo`
command can take some arguments, it can take an optional argument, but
`\endfoo` takes no argument (in the case of `DDD`, we put the argument
in an auxiliary command, that will be used at the end of the
environment). Example

::: {.container .ltx-source}
    \newenvironment{AAA}{1\begin{BBB}5}{8\end{BBB}c}
    \newenvironment{BBB}{2\begin{CCC}4}{9\end{CCC}b}
    \newenvironment{CCC}{3}{a}
    \newenvironment{DDD}[2]{#2#1\def\foo{#1}}{\foo}
    \newenvironment{EEE}[2][e]{#2#1\def\foo{#1}}{\foo}
    %latex code               translation
    \begin{AAA}67\end{AAA}    123456789abc
    \begin{DDD}678\end{DDD}   7686
    \begin{EEE}[6]78\end{EEE} 7686
    \begin{EEE}78\end{EEE}    7e8e
:::

\\newfont {#cmd-newfont}
---------

This command is a wrapper around `` `\font ``
\<doc-f.html\#cmd-font\>[\_\_ in that the expansion of
]{.title-ref}[newfontfoo{cmt at 12pt}]{.title-ref}[ is
]{.title-ref}[fontfoo=cmt at 12ptrelax]{.title-ref}\`.

\\newif {#cmd-newif}
-------

| After `\newif\iffoo`, the two commands `\footrue` and `\foofalse` are
  defined: the result of these commands is to change the meaning of
  `\iffoo` to `\iftrue` and `\iffalse` respectively. Moreover, `\iffoo`
  is let equal to `\iffalse` initially.
| ![See\...](/img/AR.png) See `` `\loop `` \<doc-loop.html\>\`\_\_ for
  an example. Note that *Tralics* wants a name with at least 3
  characters.

This is how the macro is defined in plain TeX (why does the TeXbook
mention \`edef\' ?)

::: {.container .ltx-source}
    \outer\def\newif#1{\count@\escapechar \escapechar\m@ne
      \expandafter\expandafter\expandafter
       \def\@if#1{true}{\let#1=\iftrue}%
      \expandafter\expandafter\expandafter
       \def\@if#1{false}{\let#1=\iffalse}%
      \@if#1{false}\escapechar\count@} % the condition starts out false
    \def\@if#1#2{\csname\expandafter\if@\string#1#2\endcsname}
    {\uccode`1=`i \uccode`2=`f \uppercase{\gdef\if@12{}}} % `if' is required
:::

This is how the macro is defined in LaTeX:

::: {.container .ltx-source}
    \def\newif#1{%
      \count@\escapechar \escapechar\m@ne
        \let#1\iffalse
        \@if#1\iftrue
        \@if#1\iffalse
      \escapechar\count@}
    \def\@if#1#2{%
      \expandafter\def\csname\expandafter\@gobbletwo\string#1%
                        \expandafter\@gobbletwo\string#2\endcsname
                           {\let#1#2}}
:::

\\newindex, \\\@newindex {#cmd-newindex}
------------------------

These commands allow you to use more than one index, see
[\\index](doc-i.html#indexplus).

\\newlanguage {#cmd-newlanguage}
-------------

The `\newlanguage` command is similar in principle to `` `\newcount ``
\<doc-n.html\#cmd-newcount\>\`\_\_, but it allocates a language number
(starting with 11). This is currently unused by *Tralics* that knows
only English, French and German with numbers 0, 1 and 2.

\\newlength {#cmd-newlength}
-----------

The `\newlength` command (and its synonym `\newskip`) is similar in
principle to `` `\newcount `` \<doc-n.html\#cmd-newcount\>\`\_\_, but it
allocates a skip register.

| When you say `\newlength\foo`, then `\foo` is a reference to one of
  the N skip registers. You can use `\foo` in the same way as `\skip0`.
  For instance `\foo=25pt plus 2pt` will set the dimension to 25pt plus
  2pt. It is the same as `\setlength{\foo}{25pt plus 2pt}`. You can say
  `\advance\foo by 3pt plus 4pt` if you want to increase the value, or
  you can say `\addtolength{\foo}{3pt plus 4pt}`. Note: the commands
  `\setlength` and `\addtolength` use as first argument a dimen register
  or a skip register (more generally, anything that can be preceded by
  `\advance\`, for instance `\parindent`), the second argument will be
  automatically converted (by adding zero shrink and stretch, or by
  ignoring the shrink and stretch components).
| ![See\...](/img/AR.png) (see also `` `\newcount ``
  \<doc-n.html\#cmd-newcount\>\`\_\_)
| In TeX N=256, in the current version of *Tralics* it is 1024.

\\newline {#cmd-newline}
---------

The `\newline` command is like `\\`, without optional argument. It does
not work inside an array. See [\\\\](doc-symbols.html#symbol-backslash).

\\newlinechar (internal integer) {#cmd-newlinechar}
--------------------------------

| The `\newlinechar` command can be used to change the value of the
  character that TeX uses for a new line (for instabce in `\write`) Not
  implemented in *Tralics*.
| ![See\...](/img/AR.png) (See [scanint](doc-s.html#fct-scanint) for
  details of argument scanning).

\\newmuskip {#cmd-newmuskip}
-----------

The `\newmuskip` command is similar in principle to `` `\newcount ``
\<doc-n.html\#cmd-newcount\>\`\_\_, but it allocates a muskip register.

\\newpage {#cmd-newpage}
---------

Translation of `\newpage` is `<newpage/>`.

\\newread {#cmd-newread}
---------

The `\newread` command is similar in principle to `` `\newcount ``
\<doc-n.html\#cmd-newcount\>\`\_\_, but it allocates an input stream
(first number allocated is 1, last one is 15).

\\newsavebox {#cmd-newsavebox}
------------

The `\newsavebox` command is similar to `` `\newbox ``
\<doc-n.html\#cmd-newbox\>\`\_\_ (in the current version, *Tralics* does
not check that the command is undefined).

\\newskip {#cmd-newskip}
---------

The `\newskip` command is similar in principle to `` `\newcount ``
\<doc-n.html\#cmd-newcount\>[\_\_, but it allocates a skip register. It
is the same as ]{.title-ref}`\newlength`
\<doc-n.html\#cmd-newlength\>\`\_\_.

\\newtheorem {#cmd-newtheorem}
------------

You can say `\newtheorem {X}{Y}` or `\newtheorem {X}[Z}{Y}` or
`\newtheorem {X}{Y}[T}`. This defines an environment X, labeled Y. In
the second case, it uses the counter Z, otherwise it uses X as counter.
In the last case, the counter is reset whenever T changes and the value
of T is prepended to the value of X.

There is a command `\theoremstyle` that takes an argument, and remembers
it; each theorem can see the value that was active at the definition. In
the first case shown below, and in the preview, this value is ignored.

There is a command `\theorembodyfont` that takes an argument, and
remembers it; each theorem uses this value as font for the body.

There is a command `\theoremheaderfont` that takes an argument, and
remembers it; each theorem uses this value as font for the body. For
some strange reason, this quantity is global (should be used only once).
Example.

::: {.container .ltx-source}
    \theorembodyfont{\sl}
    \theoremstyle{break}
    \newtheorem{Cor}{Corollary}
    \theoremstyle{plain}
    \setcounter{section}{17}
    \newtheorem{Exa}{Example}[section]
    {\theorembodyfont{\rmfamily}\newtheorem{Rem}{Remark}}
    \theoremstyle{marginbreak}
    \newtheorem{Lem}[Cor]{lemma}
    \theoremstyle{change}
    \theorembodyfont{\small\itshape} \newtheorem{Def}[Cor]{Definition}
    \theoremheaderfont{\scshape}
    \def\Lenv#1{\texttt{#1}}

    \begin{Cor}
     This is a sentence typeset in the theorem environment \Lenv{Cor}.
    \end{Cor}
    \begin{Exa}
     This is a sentence typeset in the theorem environment \Lenv{Exa}.
    \end{Exa}
    \begin{Rem}
     This is a sentence typeset in the theorem environment \Lenv{Rem}.
    \end{Rem}
    \begin{Lem}[Ben User]
     This is a sentence typeset in the theorem environment \Lenv{Lem}.
    \end{Lem}
    \begin{Def}[Very Impressive definition]
     This is a sentence typeset in the theorem environment \Lenv{Def}.
    \end{Def}
:::

The translation is the following.

::: {.container .xml_out}
    <p id-text='1' id='uid1'>
     <hi rend='sc'>Corollary 1 </hi>
     <hi rend='slanted'>This is a sentence typeset in the theorem environment </hi>
     <hi rend='slanted'><hi rend='tt'>Cor</hi></hi><hi rend='slanted'>.</hi>
    </p>

    <p id-text='17.1' id='uid2'>
     <hi rend='sc'>Example 17.1 </hi>
     <hi rend='slanted'>This is a sentence typeset in the theorem environment </hi>
     <hi rend='slanted'><hi rend='tt'>Exa</hi></hi>
     <hi rend='slanted'>.</hi>
    </p>

    <p id-text='1' id='uid3'>
     <hi rend='sc'>Remark 1 </hi>
     This is a sentence typeset in the theorem environment 
     <hi rend='tt'>Rem</hi>.
    </p>

    <p id-text='2' id='uid4'>
     <hi rend='sc'>lemma 2 (Ben User) </hi>
     <hi rend='slanted'>
      This is a sentence typeset in the theorem environment </hi>
     <hi rend='slanted'><hi rend='tt'>Lem</hi></hi>
     <hi rend='slanted'>.</hi>
    </p>

    <p id-text='3' id='uid5'>
     <hi rend='sc'>Definition 3 (Very Impressive definition) </hi>
     <hi rend='small1'></hi>
     <hi rend='small1'>
       <hi rend='it'>
    theorem}     This is a sentence typeset in the theorem environment 
       </hi>
     </hi>
     <hi rend='small1'><hi rend='it'><hi rend='tt'>Def</hi></hi></hi>
     <hi rend='small1'><hi rend='it'>.</hi></hi>
    </p>
:::

| The preview is the following
| ![theorems](/img/img_78.png)

Note that the theorem counter is incremented via a call to
`\refstepcounter`, in fact to `\stepcounter` plus the internal code that
defines a label. In this case, the label is put on an anonymous XML
element, then copied to the `<p>` element. If the configuration file
contains xml_xtheorem_name = \"dummy\", then the name will be `dummy`,
and the result of the translation will be

::: {.container .xml_out}
    <dummy id-text='1' id='uid3'>
     <p>
      <hi Rend='sc'>Remark 1 </hi>
      This is a sentence typeset in the theorem environment 
      <hi Rend='tt'>Rem</hi>.
     </p>
    </dummy>
:::

If the configuration file contains xml_theorem_name = \"theorem\", then
the name will be `theorem`, and the translation is a bit different, as
you can see.

::: {.container .xml_out}
    <theorem style='break' type='Cor' id-text='1'  id='uid1'>
    <head>Corollary</head>
    <p>This is a sentence typeset in the theorem environment <hi Rend='tt'>Cor</hi>.
    </p>
    </theorem>

    <theorem style='plain'  type='Exa'  id-text='17.1' id='uid2'>
    <head>Example</head>
    <p>This is a sentence typeset in the theorem environment <hi Rend='tt'>Exa</hi>.
    </p>
    </theorem>

    <theorem style='plain' type='Rem'  id-text='1' id='uid3'>
    <head>Remark</head>
    <p>This is a sentence typeset in the theorem environment <hi Rend='tt'>Rem</hi>.
    </p>
    </theorem>

    <theorem style='marginbreak'  type='Lem'  id-text='2' id='uid4'>
    <head>lemma</head>
    <alt_head>Ben User</alt_head>
    <p>This is a sentence typeset in the theorem environment <hi Rend='tt'>Lem</hi>.
    </p>
    </theorem>

    <theorem style='change' type='Def'  id-text='3' id='uid5'>
    <head>Definition</head>
    <alt_head>Very Impressive definition</alt_head>
    <p>This is a sentence typeset in the theorem environment <hi Rend='tt'>Def</hi>.
    </p>
    </theorem>
:::

\\newtoks {#cmd-newtoks}
---------

The `\newtoks` command is similar in principle to `` `\newcount ``
\<doc-n.html\#cmd-newcount\>[\_\_, but it allocates a token register.
Assuming that the first allocated register is 11, the following code
makes ]{.title-ref}[foo]{.title-ref}[ equivalent to
]{.title-ref}[Bar]{.title-ref}\`. The translation is \`123 456\'.

::: {.container .ltx-source}
    \toksdef\foo 11
    \newtoks\Bar
    \foo={123 456} \the\Bar
:::

\\newwrite {#cmd-newwrite}
----------

The `\newread` command is similar in principle to `` `\newcount ``
\<doc-n.html\#cmd-newcount\>\`\_\_, but it allocates a output stream
(first number allocated is 1, last one is 15).

\\nexists (math symbol) {#cmd-nexists}
-----------------------

The `\nexists` command is valid only in math mode. It generates:
`<mo>&nexists;</mo>` (Unicode U+2204, ∄).

\\ng (constant) {#cmd-ng}
---------------

This translates to `&eng;` or (Unicode U+14B, ŋ). For more info see the
[extended latin characters](doc-chars.html#ext-latin).

\\NG (constant) {#cmd-cng}
---------------

This translates to `&ENG;` (Unicode U+14A, Ŋ). For more info see the
[extended latin characters](doc-chars.html#ext-latin).

\\ngeq (math symbol) {#cmd-ngeq}
--------------------

The `\ngeq` command is valid only in math mode. It generates:
`<mo>&ngeq;</mo>` (Unicode U+2271, ≱).

\\ngtr (math symbol) {#cmd-ngtr}
--------------------

The `\ngtr` command is valid only in math mode. It generates:
`<mo>&ngtr;</mo>` (Unicode U+226F, ≯).

\\ni (math symbol) {#cmd-ni}
------------------

The `\ni` command is valid only in math mode. It generates:
`<mo>&ni;</mo>` (Unicode U+220B, ∋).

\\niplus (math symbol) {#cmd-niplus}
----------------------

The `\niplus` command is valid only in math mode. It generates:
`<mo>&niplus;</mo>` (Unicode U+2A2E, ⨮).

\\nleftarrow (math symbol) {#cmd-nleftarrow}
--------------------------

The `\nleftarrow` command is valid only in math mode. It generates:
`<mo>&nleftarrow;</mo>` (Unicode U+219A, ↚).

\\nLeftarrow (math symbol) {#cmd-cnleftarrow}
--------------------------

The `\nLeftarrow` command is valid only in math mode. It generates
`<mo>&nLeftarrow;</mo>` (Unicode U+21CD, ⇍).

\\nleftrightarrow (math symbol) {#cmd-nleftrightarrow}
-------------------------------

The `\nleftrightarrow` command is valid only in math mode. It generates:
`<mo>&nleftrightarrow;</mo>` (Unicode U+21AE, ↮).

\\nLeftrightarrow (math symbol) {#cmd-cnleftrightarrow}
-------------------------------

The `\nLeftrightarrow` command is valid only in math mode. It generates
`<mo>&nLeftrightarrow;</mo>` (Unicode U+21CE, ⇎).

\\nleq (math symbol) {#cmd-nleq}
--------------------

The `\nleq` command is valid only in math mode. It generates:
`<mo>&nleq;</mo>` (Unicode U+2270, ≰).

\\nless (math symbol) {#cmd-nless}
---------------------

The `\nless` command is valid only in math mode. It generates:
`<mo>&nless;</mo>` (Unicode U+226E, ≮).

\\nmid (math symbol) {#cmd-nmid}
--------------------

The `\nmid` command is valid only in math mode. It generates:
`<mo>&NotVerticalBar;</mo>` (Unicode U+2224, ∤).

\\noalign {#cmd-noalign}
---------

The `\noalign` command can be used to insert material between rows in a
table. For instance, in LaTeX, the `\hline` command is defined to be
`\noalign{\hrule height \arrayrulewidth}`, with a special hack that
allows double rules.

In *Tralics*, the only inter-row material allowed is a single `\hline`.
The `\noalign` command is not yet implemented.

\\noboundary {#cmd-noboundary}
------------

The `\noboundary` command inhibits adding an invisible boundary
character. This is used by TeX when computing ligatures and kerns. These
quantities depend on the current font. Since *Tralics* does not read
font information, the `\noboundary` is useless. It fact, the command
provokes an error.

\\nobreak {#cmd-nobreak}
---------

This commands is currently ignored.

\\nobreakspace {#cmd-nobreakspace}
--------------

The `\nobreakspace` command is identical to `~` (tilde), but cannot be
used in math mode. It generates a non-break space `&nbsp;` or `&#xA0;`.
For more info see the [latin supplement
characters](doc-chars.html#latin).

\\nocentering (Tralics command) {#cmd-nocentering}
-------------------------------

Switches to the default mode, that is not centering, nor flush left, not
flush right, nor quotation. (see also `` `\centering ``
\<doc-c.html\#cmd-centering\>\`\_\_)

\\nocite {#cmd-nocite}
--------

This commands behaves like `\cite`, but translation is empty (see also
`` `\cite `` \<doc-c.html\#cmd-cite\>\`\_\_).

\\node {#cmd-node}
------

You say `\node{x}{y}` for creating a node named x with value y in a
tree. See `` `\abarnodeconnect ``
\<doc-a.html\#cmd-abarnodeconnect\>\`\_\_ for syntax and example.

\\nodebox {#cmd-nodebox}
---------

You say `\nodebox{x}` if you want to put a box around node x. See
`` `\abarnodeconnect `` \<doc-a.html\#cmd-abarnodeconnect\>\`\_\_ for
syntax and example.

\\nodecircle {#cmd-nodecircle}
------------

You say `\nodebox[3pt]{x}` if you want to put a circle around node x.
See `` `\abarnodeconnect `` \<doc-a.html\#cmd-abarnodeconnect\>\`\_\_
for syntax and example.

\\nodeconnect {#cmd-nodeconnect}
-------------

You say `\nodeconnect[t]{x}[b]{y}` if you want to connect top of node x
to bottom of node y. See `` `\abarnodeconnect ``
\<doc-a.html\#cmd-abarnodeconnect\>\`\_\_ for syntax and example.

\\nodecurve {#cmd-nodecurve}
-----------

You say `\nodeconnect[t]{x}[b]{y}{2pt}[3pt]` if you want to connect top
of node x to bottom of node y, with a curve specified by 2pt and 3pt.
See `` `\abarnodeconnect `` \<doc-a.html\#cmd-abarnodeconnect\>\`\_\_
for syntax and example.

\\nodeoval {#cmd-nodeoval}
----------

You say `\nodeoval{x}` if you want to put an oval around node x. See
`` `\abarnodeconnect `` \<doc-a.html\#cmd-abarnodeconnect\>\`\_\_ for
syntax and example.

\\nodepoint {#cmd-nodepoint}
-----------

You say `\nodepoint{x}[4pt][5pt]` if you want to create a node named x
at the current position, with size 4pt and 5pt. See
`` `\abarnodeconnect `` \<doc-a.html\#cmd-abarnodeconnect\>\`\_\_ for
syntax and example.

\\nodetriangle {#cmd-nodetriangle}
--------------

You say `\nodetriangle{x}{y}` if you want to connect nodes x and y by a
triangle. See `` `\abarnodeconnect ``
\<doc-a.html\#cmd-abarnodeconnect\>\`\_\_ for syntax and example.

\\noexpand {#cmd-noexpand}
----------

The `\noexpand` command inhibits expansion of the token that follows. In
the example that follows, you will see "\\jobname =texput", but the
translation is `texput=texput`. In the test that follows, the tidle
character is not expanded, so category code 13 is compared to what
follows; this is the first token in the expansion of `\jn` (since this
is the first character of `\jobname`, the category code is 12, unless
the file starts with a space). In the test that follows, we compare an
unexpanded active character W; it has the same category code as
unexpanded tilde, it has the same value as `\foo`. The token that
follows `\noexpand` is considered to be `\relax` when it is expandable
(in particular, when it is undefined). The line marked "bad" gives three
errors: since unexpanded `\foo` is illegal in a control sequence name,
this aborts the construction of the name, so you get an undefined error
followed by an extra `\endcsname`. The syntax rules for `\hbox` and
`\uppercase` allow `\relax` before the open brace, so that last line is
valid. The resulting box is empty.

::: {.container .ltx-source}
    \edef \jn {\noexpand \jobname=\jobname} \show\jn \jn
    \ifcat\noexpand~\jn \bad \fi  \ifcat=\jn \else \bad \fi 
    {\let\foo=W \catcode`W=13
      \ifcat\noexpandW\noexpand~\else \bad \fi 
      \if\noexpandW\foo\else \bad \fi 
      \if\noexpandW\noexpand\foo\else \bad \fi 
    }
    \let\foo\undefined
    \csname\noexpand\foo\endcsname %bad
    \hbox to 2cm \noexpand\foo {\noexpand\foo \uppercase\noexpand\foo{}}
:::

In the example that follows, the non-expanded `\foo` finishes parsing of
the integer; it is expanded again. In the line that follows, expansion
is inhibited while scanning the `to` keyword. Hence `\foo` is expanded
again and is considered as an opening brace. In the line that follows,
the second `\noexpand` is eaten by scanning the `spread` keyword. So it
requires three `\noexpand` in order to discard `\foo`. In the two lines
that follow, the non-expanded `\foo` terminates scanning of the number,
and becomes part of the unit of measure. Consider the last line: how
many `\noexpand` tokens are needed to effectively suppress expansion
(and provoke an error)?. Quite a lot: mote than five in *Tralics* and 15
in TeX. The syntax of a dimension is quite complicated (see
[scandimen](doc-s.html#fct-scandimen)) and each time an optional thing
is tried, one `\noexpand` is eaten. For instance, one could have `em`,
`ex` or `true`. After that *Tralics* read two characters and compares
them with `pt`, `pc`, etc, while TeX scan eleven keywords, one after the
other.

::: {.container .ltx-source}
    \def\foo{0} \count0=1\noexpand\foo
    \def\foo{\bgroup}\hbox\noexpand\foo x\egroup  
    \hbox\noexpand\noexpand\foo y\egroup
    \hbox\noexpand\noexpand\noexpand\foo{z} 

    \def\foo{pt} \dimen0=2\noexpand\foo 
    \def\foo{.5pt} \dimen0=2\noexpand\foo  % error
    %\def\foo{sp} \dimen0=2\noexpand\noexpand...\foo  
:::

\\nofiles {#cmd-nofiles}
---------

This command is ignored by *Tralics*; in LaTeX it inhibits writing on
auxiliary output files.

\\nonfrenchspacing {#cmd-nonfrenchspacing}
------------------

The `\nonfrenchspacing` command is ignored. In LaTeX, this modifies the
`\sfcode` value of some punctuation characters to values greater than
1000.

\\noindent {#cmd-noindent}
----------

The `\noindent` command starts a new paragraph.

According to TeX, the only difference between `\indent` and `\noindent`
is that the first command inserts an empty hbox whose width is
`\parindent`. A new paragraph is started only if TeX is in vertical
mode, and the `\everypar` tokens are inserted in TeX\'s input. If TeX is
in vertical mode and sees a character or something like that (including
the first token of the expansion of `\leavevmode`) it adds an implicit
`\indent`.

In *Tralics*, the value of `\parindent` is ignored, as well as the
`\everypar` tokens. Paragraphs are indented by default, so that
`\noindent` adds an attribute, the other command does nothing. If the
current text is centered, flushed left or flushed right, no attribute is
added. Example

::: {.container .ltx-source}
    \def\sample{This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. \Env}
    \def\line{\sample\noindent\sample\indent\sample}
    \def\Env{Mode is normal}\line
    \begin{center}\def\Env{Mode is center}\line\end{center}
    \begin{flushleft}\def\Env{Mode is left}\line\end{flushleft}
    \begin{flushright}\def\Env{Mode is right}\line\end{flushright}
:::

::: {.container .xml_out}
    <p>
    This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is normal</p>
    <p noindent='true'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is normal</p>
    <p>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is normal</p>

    <p rend='center'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is center</p>
    <p rend='center'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is center</p>
    <p rend='center'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is center</p>

    <p rend='flushed-left'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is left</p>
    <p rend='flushed-left'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is left</p>
    <p rend='flushed-left'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is left</p>

    <p rend='flushed-right'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is right</p>
    <p rend='flushed-right'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is right</p>
    <p rend='flushed-right'>This is some text explaining and showing how text is centered,
    flushed left or flushed right or indented or not indented. Mode is right</p>
:::

![example of noindent, flushleft, flushright, center](/img/img_28.png)

\\nointerlineskip {#cmd-nointerlineskip}
-----------------

The `\nointerlineskip` command is ignored. In TeX, it sets `\prevdepth`
dimension to a magic value.

\\nolimits {#cmd-nolimits}
----------

| The `\nolimits` command is valid only in math mode. It describes how
  indices should be positioned. In the case of `\mathop a\limits ^b`,
  the translation is a `<mover>` element containing a and b, rather than
  a `<msup>`. If you forget the `\mathop`, an error will be signaled by
  TeX, but *Tralics* simply ignores the command. There are three flags,
  `\limits`, `\nolimits` and `\displaylimits` whose meaning is: use
  always over, use never over, use over in display mode only. More than
  one prefix can be given, the last one has precedence. A command like
  `\lim` has `\mathop` and `\displaylimits` flags, while `\sin` has
  `\mathop` and `\nolimits` flags. It happens that the kernel in
  `<mover>` can have a \`movablelimits\' attribute, case where the
  effect is the same as `\displaylimits`; this may confuse *Tralics*, in
  the case where the attribute is implicit.
| ![See\...](/img/AR.png) (see also [here](mml_ex.html#limits)) For
  details see `` `\mathord `` \<doc-m.html\#cmd-mathord\>\`\_\_.

::: {.container .ltx-source}
    \def\A#1{\mathop a #1_b, \mathop a#1^c, \mathop a#1_b^c}
    $\A{} \A\limits \A\nolimits \A\displaylimits $
    \[\A{} \A\limits \A\nolimits \A\displaylimits \]
:::

::: {.container .xml_out}
    <formula type='inline'>
      <math xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow>
          <msub><mi>a</mi> <mi>b</mi> </msub>          <mo>,</mo>
          <msup><mi>a</mi> <mi>c</mi> </msup>          <mo>,</mo>
          <msubsup><mi>a</mi> <mi>b</mi> <mi>c</mi></msubsup>
          <munder><mi>a</mi> <mi>b</mi> </munder>      <mo>,</mo>
          <mover><mi>a</mi> <mi>c</mi> </mover>        <mo>,</mo>
          <munderover><mi>a</mi> <mi>b</mi> <mi>c</mi></munderover>
          <msub><mi>a</mi> <mi>b</mi> </msub>          <mo>,</mo>
          <msup><mi>a</mi> <mi>c</mi> </msup>          <mo>,</mo>
          <msubsup><mi>a</mi> <mi>b</mi> <mi>c</mi> </msubsup>
          <msub><mi>a</mi> <mi>b</mi> </msub>          <mo>,</mo>
          <msup><mi>a</mi> <mi>c</mi> </msup>          <mo>,</mo>
          <msubsup><mi>a</mi> <mi>b</mi> <mi>c</mi> </msubsup>
        </mrow>
      </math>
    </formula>
    <formula type='display'>
      <math mode='display' xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow> 
          <munder><mi>a</mi> <mi>b</mi> </munder>      <mo>,</mo>
          <mover><mi>a</mi> <mi>c</mi> </mover>        <mo>,</mo>
          <munderover><mi>a</mi> <mi>b</mi> <mi>c</mi> </munderover>
          <munder><mi>a</mi> <mi>b</mi>  </munder>     <mo>,</mo>
          <mover><mi>a</mi> <mi>c</mi> </mover>        <mo>,</mo>
          <munderover><mi>a</mi> <mi>b</mi> <mi>c</mi> </munderover>
          <msub><mi>a</mi> <mi>b</mi> </msub>          <mo>,</mo>
          <msup><mi>a</mi> <mi>c</mi> </msup>          <mo>,</mo>
          <msubsup><mi>a</mi> <mi>b</mi> <mi>c</mi> </msubsup>
          <munder><mi>a</mi> <mi>b</mi> </munder>      <mo>,</mo>
          <mover><mi>a</mi> <mi>c</mi> </mover>        <mo>,</mo>
          <munderover><mi>a</mi> <mi>b</mi> <mi>c</mi> </munderover>
       </mrow>
     </math>
    </formula>
:::

\\\@nomathml (Internal Tralics integer) {#cmd-nomathml}
---------------------------------------

The variable `\@nomathml` controls translation of mathematical formulas.
The default value is zero, and a MathML object is constructed. If the
variable is positive, all math-commands translate to themselves; for
instance the translation of `\int_x^{-\infty}` becomes `\int_x^-\infty`.
If the argument is negative, the translation depends on whether the
argument is -2 or -3 or some other value. Consider the following input:

::: {.container .ltx-source}
    \def\myvar{\phi}
    $\int_{-\infty}^\myvar f(x) dx=\mathrm{O}\,\left(\frac{1}\myvar\right)$
    $x_{\mbox{{\scriptsize{H\,{\sc i}}}}}$
    \begin{equation}\text{a}=\hbox{b}=\mbox{c}\end{equation}
:::

This is the translation in case `\@nomathml=-2`. You can notice that
translation of simple objects like `\phi` is an empty element of the
same name, and that braces (even implicit ones, for instance the second
argument of the fraction) produces a `<arg>` element.

::: {.container .xml_out}
    <texmath textype='inline' type='inline'>
       <int/><subscript><arg>-<infty/></arg></subscript>
             <superscript><phi/></superscript>
             f(x) dx=<mathrm/><arg>O</arg>
       <elt name=','/><left del='('><frac><arg>1</arg><arg><phi/></arg></frac>
       <right del=')'>
    </texmath>
    <texmath textype='inline' type='inline'>
       x<subscript>
         <arg>
          <mbox>
           <arg>
            <scriptsize/><arg>H<elt name=','/><arg><sc/>i</arg></arg>
           </arg>
          </mbox>
         </arg>
       </subscript>
    </texmath>
    <texmath id-text='1' id='uid1' textype='equation' type='display'>
      <text>a</text>=<hbox>b</hbox>=<mbox>c</mbox>
    </texmath>
:::

Translation of the same example, with `\@nomathml=-1`. It is a single
XML element, containing the TeX source (after macro-expansion).

::: {.container .xml_out}
    <texmath textype='inline' type='inline'>
       \int _{-\infty }^\phi f(x) dx=\mathrm {O}\,\left(\frac{1}{\phi }\right)
    </texmath>
    <texmath textype='inline' type='inline'>
     x_{\mbox{{\scriptsize {H\,{\sc i}}}}}</texmath>
    <texmath id-text='1' id='uid1' textype='equation' type='display'>
       \text{a}=\hbox{b}=\mbox{c}
    </texmath>
:::

Translation of the same example, with `\@nomathml=-3`. The translation
is a merge of the cases 0 and -1. More precisely, a `<texmath>` is
created, and inserted in the `<formula>` after the `<math>`.

::: {.container .xml_out}
    <formula type='inline'>
      <math xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow>
          <msubsup>
            <mo>&int;</mo> 
            <mrow><mo>-</mo><mi>&infin;</mi></mrow> 
            <mi>&phiv;</mi> 
          </msubsup>
          <mi>f</mi>
          <mrow><mo>(</mo><mi>x</mi><mo>)</mo></mrow>
          <mi>d</mi><mi>x</mi><mo>=</mo>
          <mi mathvariant='normal'>O</mi><mspace width='0.166667em'/>
          <mfenced separators='' open='(' close=')'>
            <mfrac><mn>1</mn> <mi>&phiv;</mi></mfrac>
          </mfenced>
        </mrow>
      </math>
      <texmath>
        \int _{-\infty }^\phi f(x) dx=\mathrm {O}\,\left(\frac{1}{\phi }\right)
      </texmath>
    </formula>
    <formula type='inline'>
      <math xmlns='http://www.w3.org/1998/Math/MathML'>
        <msub>
          <mi>x</mi> 
          <mrow><mtext>H</mtext><mspace width='0.166667em'/><mtext>i</mtext></mrow> 
        </msub>
      </math>
      <texmath>x_{\mbox{{\scriptsize {H\,{\sc i}}}}}</texmath>
    </formula>
    <formula id-text='1' id='uid1' textype='equation' type='display'>
      <math mode='display' xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow><mtext>a</mtext><mo>=</mo><mtext>b</mtext><mo>=</mo><mtext>c</mtext></mrow>
      </math>
      <texmath>\text{a}=\hbox{b}=\mbox{c}
      </texmath>
    </formula>
:::

If you try to put an attribute pair to the formula or math expression,
the behavior depends on the switch. If it is -2, the translation is a
`<thismathattribute>` or `<formulaattribute>` element. In all other
cases, attributes are added to the `<formula>`, `<math>` or `<texmath>`
elements (this last element receives both attributes). Example

::: {.container .ltx-source}
    $\thismathattribute{a}{b}\formulaattribute{c}{d} e$
:::

Here are the translation when the variable is 0, -1, -2 and -3.

::: {.container .xml_out}
    <formula type='inline' c='d'>
      <math xmlns='http://www.w3.org/1998/Math/MathML' a='b'>
        <mi>e</mi>
      </math>
    </formula>
    <texmath c='d' a='b' textype='inline' type='inline'> e</texmath>
    <texmath textype='inline' type='inline'>
      <thismathattribute><arg>a</arg><arg>b</arg></thismathattribute>
      <formulaattribute><arg>c</arg><arg>d</arg></formulaattribute>
      e
    </texmath>
    <formula type='inline' c='d'>
      <math xmlns='http://www.w3.org/1998/Math/MathML' a='b'>
        <mi>e</mi>
      </math>
      <texmath c='d' a='b'> e</texmath>
    </formula>
:::

\\\@nomathswi, \\\@nomathswii (Tralics commands) {#cmd-nomathsw}
------------------------------------------------

In the case where `\@nomathml=-3` (see above) Tralics reads a math
formula, expanding all commands; the resulting list is then converted
twice as an XML expression. A font switch like `\mathrm` is interpreted
as `\mml@font@normal`. A special marker is inserted in the list,
preventing this token to appear in the result. More generally, what
follows `\@nomathswi` appears only in the `<math>` object, and what
follows `\@nomathswii` appears only in `<texmath>` object. This
mechanism is used whatever the value of `\@nomathml`. Example

::: {.container .ltx-source}
    $a \@nomathswi{xy} b \@nomathswii{zt} c$ 
:::

Here are the translation when the variable `\@nomathml` is 0, -1, and
-3.

::: {.container .xml_out}
    <formula type='inline'>
      <math xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow><mi>a</mi><mrow><mi>x</mi><mi>y</mi></mrow><mi>b</mi><mi>c</mi></mrow> 
      </math>
    <texmath textype='inline' type='inline'>a  b {zt} c</texmath>
    </formula>
    <formula type='inline'>
      <math xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow><mi>a</mi><mrow><mi>x</mi><mi>y</mi></mrow><mi>b</mi><mi>c</mi></mrow>
      </math>
      <texmath>a  b {zt} c</texmath>
    </formula>
:::

Other example. Assume that you want to create a command `\varPi` which
is the upper case equivalent of `\varpi`. This command should have the
same translation as `\Pi`, but should be presented as `\varPi` in
no-mathml mode. Here is a possible definition. Note that \"what follows
`\@nomathswii`\" was a list in the previous example, and braces are kept
in the XML; here is the expansion of `\noexpand`, thus a control
sequence name.

::: {.container .ltx-source}
    \def\varPi{\@nomathswi\Pi \@nomathswii\noexpand\varPi}
    $a+\varPi$
:::

Here are the translation when the variable `\@nomathml` is -3.

::: {.container .xml_out}
    <formula type='inline'>
      <math xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow><mi>a</mi><mo>+</mo><mi>&Pi;</mi></mrow>
      </math>
      <texmath>a+\varPi </texmath>
    </formula>
:::

\\nolinebreak {#cmd-nolinebreak}
-------------

The `\nolinebreak` command takes an optional argument. It is used to
inhibit line break at this position in the paragraph. This command is
ignored in *Tralics*.

\\nonscript {#cmd-nonscript}
-----------

The `\nonscript` command is only valid in math mode. A special item is
inserted in the current math list. After all tokens are converted into
MathML fragments, if the following token is a `<mspace>` it will be
removed, provided that the current style is scriptstyle or scriptscript
style. Example

::: {.container .ltx-source}
    \def\XX{\nonscript\,}
    $a\XX b_{c\XX d} a\XX b_{\textstyle c\XX d} $
:::

![nonscript](/img/img_83.png)

\\nonstopmode {#cmd-nonstopmode}
-------------

You can prefix the command `\nonstopmode` with `\global`. Nothing
happens, since batch-mode is the only interaction mode.

\\nonumber {#cmd-nonumber}
----------

Since version 2.15.4, `\nonumber` is the same as `` `\notag ``
\<\#cmd-notag\>\`\_\_; previously it was ignored.

\\noopsort {#cmd-noopsort}
----------

This command takes one argument and ignores it.

\\nopagebreak {#cmd-nopagebreak}
-------------

The `\nopagebreak` command takes an optional argument. It is used to
inhibit page break at this position in the text. This command is ignored
in *Tralics*.

\\normalbaselines {#cmd-normalbaselines}
-----------------

In LaTeX, this sets `\lineskip`, `\baselineskip` and `\lineskiplimit` to
`\normalXXX` (see description below). Does nothing in *Tralics*.

\\normalbaselineskip (rubber length) {#cmd-normalbaselineskip}
------------------------------------

Set by LaTeX to 12pt, updated whenever the font size changes, unused by
*Tralics*.

\\normallineskip (rubber length) {#cmd-normallineskip}
--------------------------------

Set by LaTeX to 1pt, unused by *Tralics*.

\\normallineskiplimit (rigid length) {#cmd-normallineskiplimit}
------------------------------------

Set by LaTeX to 0pt, unused by *Tralics*.

\\normalcolor {#cmd-normalcolor}
-------------

Switches to the default color; see `` `\color ``
\<doc-c.html\#cmd-color\>\`\_\_.

\\normalfont, \\<reset@font> {#cmd-normalfont}
----------------------------

The `\normalfont` command is a command that selects a font of normal
family, series and shape. That is, roman family, medium series and
upright shape. It is the same as `\rm`.

In LateX, it uses
`\encodingdefault \familydefault \seriesdefault \shapedefault` but the
last three commands are not implemented in *Tralics*. Remember that the
encoding is always Unicode. There is a comment in the LaTeX source that
says: The user interface name for `\reset@font` is `\normalfont`.

\\normalsize {#cmd-normalsize}
------------

The `\normalsize` command is a command that selects a font of normal
size. For an example of fonts, see `` `\rm ``
\<doc-r.html\#cmd-rm\>\`\_\_.

\\not {#cmd-not}
-----

The `\not` command is most often translated by *Tralics* as `\neg` (this
is wrong). But MathML gives no easy way to negate an operator\... There
are some hacks: `\not=`is replaced by `\ne`. This can be wrong in cases
like `x_\not=1`.

It can be used as boolean negator inside conditionals defined by
`` `\ifthenelse `` \<doc-i.html\#cmd-ifthenelse\>\`\_\_.

\\NOT {#cmd-cnot}
-----

It can be used as boolean negator (equivalent to `\not`) inside
conditionals defined by `` `\ifthenelse ``
\<doc-i.html\#cmd-ifthenelse\>\`\_\_.

\\notag {#cmd-notag}
-------

We describe here the behavior of version 2.15.4, and following. There
are three kinds of math expressions: (a) no equation number, (b) one
equation number, and (c) multiple equation numbers (one for each row).
An equation number is generated by increasing the equation counter, this
creates a label. The command `\nonumber` inhibits incrementation of the
counter, and no tag is produced; for this reason, it has an alias
`\notag`. You can also say `\tag{foo}`, this inhibits incrementing the
equation counter, but creates a tag. Note that a tag implies an anchor,
to which a `\label` can refer.

In *Tralics* the anchor is associated to the `formula`. This means: at
most one tag, at most one label, and case (c) becomes problematic. See
description of the [\\tag](doc-t.html#cmd-tag) command for details. If
the counter `\multi@math@label` is non-zero, or option -multi_math_label
has been used, then the anchor is associated to the row. This means, for
each row: at most one tag, at most one label. So: in case (a), `\notag`
is illegal, as well as `\tag`; in case (b) `\notag` and `\tag{...}`
inhibit incrementing the equation counter; at most one `\tag{...}` is
allowed; in the case a label is used but no tag is given, then `\notag`
is ignored; case (c) is like (b), but each row is considered as formula.
See [\\multi\@math\@label](doc-m.html#cmd-multimathlabel) for examples.

\\notin (math symbol) {#cmd-notin}
---------------------

The `\notin` command gives a \`not in\' symbol: `<mo>&notin;</mo>`
(Unicode U+2209, ∉). See also description of the `` `\smallint ``
\<doc-s.html\#cmd-smallint\>\`\_\_ command.

\\\@notprerr {#cmd-notprerr}
------------

If you say `\let\foo\@notprerr`, then calling `\foo` provokes the error
*Can be used only in preamble*

\\notrivialmath (Tralics integer) {#cmd-notrivialmath}
---------------------------------

You can say `\notrivialmath=93`, this changes the value of an internal
counter (See [scanint](doc-s.html#fct-scanint) for details of argument
scanning). By default, the value is one, unless you call *Tralics* with
the switch -trivialmath or -notrivialmath. The value C of this counter
(modulo 8) is considered. If the first bit of C is set (i.e., if C is
odd), then `$1^e$, X$^{eme}$ $4^{i\grave{e}me}$` is considered a
sequence of trivial math expressions, and translated as
`1<hi rend='sup'>e</hi>`, or `X<hi rend='sup'>e</hi>`, or
`4<hi rend='sup'>e</hi>`, that may be rendered as 1^e^, X^e^, 4^e^.
Expressions that match are formed of an optional sequence of digits, a
superscript character, a special exponent; valid exponents are th, rd,
rt, st (for English), or e, ieme, eme, ième, ier, er, iemes, ièmes, es,
ère, re (for French). The exponent can contain font changes like
`\small` or `\rm`. As you can see, in French, there may be some
transformation, because many people using wrong abbreviations.

If the second bit of C is set (C is 2, 3, 6, 7 modulo 8) then
`$x$ $1$ $\alpha$ $\pm$` is considered as a set of trivial math
formulas, translated into
`<formula   type='inline'><simplemath>x</simplemath></formula> 1   &alpha &pm;`.
Note that a formula consisting of a single digit matches two rules.
Most, but not all math symbols, produce a non-math value if they are the
only token in the formula. Character symbols like \'+\', \'\*\', are not
trivial; exception `$-$` is translated as en-dash (Unicode U+2013).

If the third bit of C is set (i.e. C is 4, 5, 6, 7 modulo 8), then
`$_{foo}$ $^{2+3}$` is considered as a sequence of trivial math
expressions and translated as
`<hi rend='sub'>foo</hi> <hi rend='sup'>2+3</hi>`. Candidates are
formulas starting with hat or underscore, followed by a character, or a
list containing only characters. In the case `$^{eme}$`, this rule is
applied before the rule that says that the translation should be
`<hi rend='sup'>e</hi>`. Font changes are allowed, provided that it is
the first token in the list, and the font is one of it, rm, sf, tt and
bf, so that `$_{\bf foo}$` is the same as `\textsubscript{{\bf foo}}`.

In some examples above, the expression is compiled like
`\textsuperscript` or `\textsubscript` (see `` `\rm ``
\<doc-r.html\#cmd-rm\>\`\_\_ for how the change the translation of font
commands). The default value is 7, and the option -notrivialmath sets
the flag to 0.

\\nparallel (math symbol) {#cmd-nparallel}
-------------------------

The `\nparallel` command is valid only in math mode. It generates
`<mi>&nparallel;</mi>` (Unicode U+2226, ∦).

\\nprec (math symbol) {#cmd-nprec}
---------------------

The `\nprec` command is valid only in math mode. It generates
`<mi>&nprec;</mi>` (Unicode U+2280, ⊀).

\\nrightarrow (math symbol) {#cmd-nrightarrow}
---------------------------

The `\nrightarrow` command is valid only in math mode. It generates
`<mi>&nrightarrow;</mi>` (Unicode U+219B, ↛).

\\nRightarrow (math symbol) {#cmd-cnrightarrow}
---------------------------

The `\nRightarrow` command is valid only in math mode. It generates
`<mo>&nRightarrow;</mo>` (Unicode U+21CF, ⇏).

\\nsim (math symbol) {#cmd-nsim}
--------------------

The `\nsim` command is valid only in math mode. It generates
`<mi>&nsim;</mi>` (Unicode U+2241, ≁).

\\nsubseteq (math symbol) {#cmd-nsubseteq}
-------------------------

The `\nsubseteq` command is valid only in math mode. It generates
`<mi>&nsubseteq;</mi>` (Unicode U+2288, ⊈).

\\nsucc (math symbol) {#cmd-nsucc}
---------------------

The `\nsucc` command is valid only in math mode. It generates
`<mi>&nsucc;</mi>` (Unicode U+2281, ⊁).

\\nsupseteq (math symbol) {#cmd-nsupseteq}
-------------------------

The `\nsupseteq` command is valid only in math mode. It generates
`<mi>&nsupseteq;</mi>` (Unicode U+2289, ⊉).

\\ntriangleleft (math symbol) {#cmd-ntriangleleft}
-----------------------------

The `\ntriangleleft` command is valid only in math mode. It generates
`<mi>&ntriangleleft;</mi>` (Unicode U+22EA, ⋪).

\\ntrianglelefteq (math symbol) {#cmd-ntrianglelefteq}
-------------------------------

The `\ntrianglelefteq` command is valid only in math mode. It generates
`<mi>&ntrianglelefteq;</mi>` (Unicode U+22EC, ⋬)

\\ntrianglelefteqslant (math symbol) {#cmd-ntrianglelefteqslant}
------------------------------------

The `\ntrianglelefteqslant` command is valid only in math mode. It
generates `<mi>&ntrianglelefteq;</mi>` (Unicode U+22EC, ⋬).

\\ntriangleright (math symbol) {#cmd-ntriangleright}
------------------------------

The `\ntriangleright` command is valid only in math mode. It generates
`<mi>&ntriangleright;</mi>` (Unicode U+22EB, ⋫).

\\ntrianglerighteq (math symbol) {#cmd-ntrianglerighteq}
--------------------------------

The `\ntrianglerighteq` command is valid only in math mode. It generates
`<mi>&ntrianglerighteq;</mi>` (Unicode U+22ED ⋭) .

\\ntrianglerighteqslant (math symbol) {#cmd-ntrianglerighteqslant}
-------------------------------------

The `\ntrianglerighteqslant` command is valid only in math mode. It
generates `<mi>&ntrianglerighteq;</mi>` (Unicode U+22ED; ⋭).

\\nu (math symbol) {#cmd-nu}
------------------

The `\nu` command is valid only in math mode. It generates a Greek
letter: `<mi>&nu;</mi>` (Unicode U+3BD, ν). See description of the
`` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\null {#cmd-null}
------

Because of the definition `\def\null{\hbox{}}`, the effect of the
`\null` is to put, on the XML tree, an element that is not visible in
the printed output.

\\nullfont {#cmd-nullfont}
----------

The `\nullfont` command is a reference to a font. It can be used
wherever a font is required. However no character is defined in this
font, and all parameters are zero. For instance `\textfont0=\nullfont`
is valid.

\\nulldelimiterspace (rigid length) {#cmd-nulldelimiterspace}
-----------------------------------

| When you say `\nulldelimiterspace=5pt`, then TeX will use 5pt as the
  width of null delimiters (for instance `\right.`; also on the left and
  right of a normal fraction, because `\over` is the same as
  `\overwidthdelims..`). It is ignored by *Tralics*.
| ![See\...](/img/AR.png) (See [scandimen](doc-s.html#fct-scandimen) for
  details of argument scanning).

\\number {#cmd-number}
--------

The `\number` command reads a number (a signed 32bit integer) via the
[scanint](doc-s.html#fct-scanint) procedure. The expansion of the
command is the list of tokens (characters with `\catcode` 12) of the
decimal expansion of the number. In the example that follows, the
expansion of `\Test` is `2`.

::: {.container .ltx-source}
    \def\Test-#174{#1}
    \count3=-27
    \expandafter\Test\number\count3 4
:::

\\numberedverbatim {#cmd-numberedverbatim}
------------------

After the `\numberedverbatim` command is issued, lines produced by the
`` `verbatim `` \<doc-v.html\#env-verbatim\>[\_\_ environment are
preceded by a line number. This command has no effect on the
]{.title-ref}[Verbatim]{.title-ref}\` environment.

\\numberwithin {#cmd-numberwithin}
--------------

If you say `\numberwithin{foo}{bar}` then an error is signaled unless
both arguments are counters. The first counter is dependent on the
second one (reset when stepped). Moreover `\thefoo` is
`\thebar.\arabic{foo}`. An optional argument can be used, it will
replace the `\arabic` token. This command introduced in Version 2.13.1.

\\numexpr {#cmd-numexpr}
---------

As in the case of ε-TeX, *Tralics* provides the notion of expressions of
type number, dimen, glue or muglue, that can be used whenever a quantity
of that type is needed. Such an expression is read by the scanning
mechanism; basically [scanint](doc-s.html#fct-scanint) and friends are
used to read a quantity, and `\multiply` and friends are used to perform
operations. The four commands that can be used are `\numexpr`,
`\dimexpr`, `\glueexpr` and `\muexpr`. They determine a type *t*, the
type of the result, and read an expression, that is followed by an
optional `\relax` (that will be read). When scanning for an operator or
the end of an expression, spaces are discarded. An expression consists
of one or more terms of type *t*, that are added or subtracted. A term
of type *t* consists of an initial factor of type *t*, multiplied or
divided by a numeric (integer) factor. Finally, a factor is either a
quantity of type *t*, or a parenthesized expression. Example.

::: {.container .ltx-source}
    \ifdim \dimexpr(2pt-5pt) *\numexpr 3-3*13/5\relax + 34pt/2=32pt
    \else\bad\fi
:::

Here the `\relax` terminates the `\numexpr`. This is the trace. You will
see *expr so far* when a term is converted into an expression (prefix
\`=\'), or after an addition or subtraction (prefix \`+\' or \`-\'). You
will see *term so far* after a multiplication or division (prefix \'*\'
or \'/\') or a scaling (prefix backslash). In the case of a*b/c, a 64bit
intermediate product is computed.

::: {.container .log_out}
    [8] \ifdim \dimexpr(2pt-5pt) *\numexpr 3-3*13/5\relax + 34pt/2=32pt
    +\ifdim1
    +scanint for \dimexpr->2
    +scandimen for \dimexpr->2.0pt
    +expr so far for \dimexpr= 2.0pt
    +scanint for \dimexpr->5
    +scandimen for \dimexpr->5.0pt
    +expr so far for \dimexpr- -3.0pt
    +scanint for \numexpr->3
    +expr so far for \numexpr= 3
    +scanint for \numexpr->3
    +scanint for \numexpr->13
    +scanint for \numexpr->5
    +term so far for \numexpr\ 8
    +expr so far for \numexpr- -5
    +scan for \numexpr= -5
    +scanint for \dimexpr->-5
    +term so far for \dimexpr* 15.0pt
    +expr so far for \dimexpr= 15.0pt
    +scanint for \dimexpr->34
    +scandimen for \dimexpr->34.0pt
    +scanint for \dimexpr->2
    +term so far for \dimexpr/ 17.0pt
    +expr so far for \dimexpr+ 32.0pt
    +scan for \dimexpr= 32.0pt
    +scandimen for \ifdim->32.0pt
    +scanint for \ifdim->32
    +scandimen for \ifdim->32.0pt
    +iftest1 true
:::

Note that `3*13/5` is 8-1/5, and this is rounded to 8. In the case of
`\divide`, the result is truncated. All intermediate expressions are
checked for overflow, which is 2^31^ for an integer, and 2^30^ otherwise
(in magnitude). This means that dimensions and components of glue must
be less than 2^14^ in units of pt, mu or fil.

One important point is that these operations do no side effects, hence
can be used inside an `\edef`. If used out of context, you can see error
messages like *You can\'t use \`numexpr\' in horizontal mode*, (the
messages depends on the current mode), in *Tralics*, the error is *Read
only variable \\numexpr*, because these operations are implemented as
the value of a read only variable. Example

::: {.container .ltx-source}
    \def\foo#1#2{\number#1
      \ifnum#1<#2, %
      \expandafter\foo
      \expandafter{\number\numexpr#1+1\expandafter}%
      \expandafter{\number#2\expandafter}%
      \fi}

    \edef\Bar{\foo{7}{13}}
    \def\xBar{7, 8, 9, 10, 11, 12, 13}
    \ifx\Bar\xBar\else \bad\fi
:::

\\numero, \\no {#cmd-numero}
--------------

The `\numero` and `\no` commands translate the same as
`n\textsuperscript{o}\xspace`. Before version 2.8.2, it was `&numero;`,
an entity defined by the raweb.

\\Numero, \\No {#cmd-cnumero}
--------------

The `\Numero` and `\No` commands translate the same as
`N\textsuperscript{o}\xspace`. Before version 2.8.2, it was `&Numero;`,
an entity defined by the raweb.

\\nvdash, \\nvDash, \\nVdash, \\nVDash (math symbol) {#cmd-nvdash}
----------------------------------------------------

Thes commands are the negations of `` `\vdash, \vDash, \Vdash,\VDash ``
\<doc-v.html\#cmd-vdash\>[\_\_. They can be used in math mode only.
Translation is a ]{.title-ref}[\<mo\>]{.title-ref}[ containing a
]{.title-ref}[&nvDash;]{.title-ref}[ (U+22AC; ⊬),
]{.title-ref}[&nvDash;]{.title-ref}[ (Unicode U+22AD, ⊭),
]{.title-ref}[&nVdash;]{.title-ref}[ (U+22AE, ⊮), or
]{.title-ref}[&nVDash;]{.title-ref}\` (U+22AF; ⊯) respectively.

\\nwarrow (math symbol) {#cmd-nwarrow}
-----------------------

| The `\nwarrow` command is valid only in math mode. It generates an
  arrow that points North-West: `<mo>&nwarrow;</mo>` (Unicode U+2196,
  ↖).
| ![See\...](/img/AR.png) See description of the
  [\\leftarrow](doc-l.html#cmd-leftarrow) command.
