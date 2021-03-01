All commands, alphabetic order; letter W
========================================

This page contains the description of [\\wd](#cmd-wd),
[\\wedge](#cmd-wedge), [\\whiledo](#cmd-whiledo),
[\\\@whiledim](#cmd-whiledim), [\\\@whilenum](#cmd-whilenum),
[\\\@whilesw](#cmd-whilesw), [\\widehat](#cmd-widehat),
[\\widetilde](#cmd-widetilde), [\\\@width](#cmd-width),
[\\widowpenalties](#cmd-widowpenalties),
[\\widowpenalty](#cmd-widowpenalty), [\\widthof](#cmd-widthof),
[\\wlog](#cmd-wlog), [\\wp](#cmd-wp), [\\wr](#cmd-wr), [wrapfigure,
wraptable](#env-wrapfigure), [\\write](#cmd-write).

------------------------------------------------------------------------

\\wd {#cmd-wd}
----

A command like `\wd0=2\wd1` says to replace the width of the box number
0 by twice the width of box number one. See
[scanint](doc-s.html#fct-scanint) for how integers are read (here the
integer is zero, it should be a number between 0 and 255 in TeX, 1023 in
*Tralics*). See [scandimen](doc-s.html#fct-scandimen) for how dimensions
are read (here `2\wd1` is the dimension).

Changing the dimension of the box does not change its content: if you
say `\hbox to 0pt{...}`, you will get an overflow hbox, but if you say
`\setbox0= \hbox{...}\wd0=0pt \box0`, you will get a box that is neither
overfull nor underfull, the result is of width zero. This is more or
less the same as `\hbox to 0pt{...\hss}`.

*Tralics* does not use nor remember box dimensions. In the example above
`2\wd1` evaluates to 0pt, and modifying `\wd0` does not modify the box.

\\wedge (math symbol) {#cmd-wedge}
---------------------

The `\wedge` command is valid only in math mode. It generates a binary
operator: `<mo>&wedge;</mo>` (Unicode U+2227, ∧). See description of the
`` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\whiledo {#cmd-whiledo}
---------

The `\whiledo` command is provided by the ifthenelse package. It takes
two arguments: a test and a body. The test is evaluated via
`` `\ifthenelse `` \<doc-i.html\#cmd-ifthenelse\>\`\_\_. It if is true,
the body is evaluated, and the test is done again.

The original LaTeX definition uses the `\@whilesw` command, and a
special boolean `\if@whiledo`. It is shown here.

::: {.container .ltx-source}
    \makeatletter
    \newif\if@whiledo
    \long\def\whiledo#1#2{%
      \ifthenelse{#1}%
        {\@whiledotrue
         \@whilesw\if@whiledo\fi
           {#2%
            \ifthenelse{#1}\@whiledotrue\@whiledofalse}}%
        {}%
      }
:::

Here is an example of code

::: {.container .ltx-source}
    \newcounter{ca}\newcounter{cb}
    \newcommand{\printgcd}[2]{%
      \setcounter{ca}{#1}\setcounter{cb}{#2}%
      Gcd(#1,#2) = 
      \whiledo{\not\(\value{ca}=\value{cb}\)}%
        {\ifthenelse{\value{ca}>\value{cb}}%
          {\addtocounter{ca}{-\value{cb}}}%
          {\addtocounter{cb}{-\value{ca}}}%
        gcd(\arabic{ca},\arabic{cb}) = }%
      \arabic{ca}.}
    \printgcd{144}{272}
:::

The translation is the following. ![gcd](/img/img_79.png)

This is another way for the same command. The first time we enter
`\@whilesw`, the test is true. Here we print the value at the start of
the loop instead of the end.

::: {.container .ltx-source}
    \newif\iftest
    \newcommand{\printgcd}[2]{%
      \setcounter{ca}{#1}\setcounter{cb}{#2}%
      \testtrue
      \@whilesw\iftest gcd(\arabic{ca},\arabic{cb}) = \fi{%
       \ifnum\value{ca}=\value{cb}\testfalse\else
        \ifnum\value{ca}>\value{cb}%
          \addtocounter{ca}{-\value{cb}}\else
          \addtocounter{cb}{-\value{ca}}\fi
    \fi}%
      \arabic{ca}.}
    \printgcd{144}{272}
:::

Here we use `\@whilenum`. The code is: while C is less than D, then say
A=C, B=D-C. In any case, put in C the smallest of A, B, and in D the
largest. The big trouble is that `\@whilenum` compares two numbers, and
the test is less-than, greater-than and equal-than. There is no
different-from. You just cannot say: \`while A is different from B do\'.

::: {.container .ltx-source}
    \newcounter{cc}\newcounter{cd}
    \def\assigncounter{%
     \ifnum\value{ca}<\value{cb}%
      \setcounter{cc}{\value{ca}}%
      \setcounter{cd}{\value{cb}}%
     \else 
      \setcounter{cc}{\value{cb}}%
      \setcounter{cd}{\value{ca}}%
      \fi}

    \def\subtractcounter{%
     \setcounter{cb}{\value{cd}}%
     \setcounter{ca}{\value{cc}}%
     \addtocounter{cb}{-\value{cc}}}%
    \let\printgcd\relax
    \newcommand{\printgcd}[2]{%
      \setcounter{ca}{#1}\setcounter{cb}{#2}%
      \assigncounter
      \@whilenum \value{cc}<\value{cd} Gcd(\arabic{cc},\arabic{cd}) = \do{%
         \subtractcounter\assigncounter}%
      \arabic{ca}.}
    \printgcd{144}{272}
:::

This is the same code, but we use dimensions. Note how dimensions are
converted to integers and vice-versa.

::: {.container .ltx-source}
    \newlength\cC\newlength\cD
    \def\assignlength{%
     \ifnum\value{ca}<\value{cb}%
      \setlength\cC{\value{ca}sp}%
      \setlength\cD{\value{cb}sp}%
     \else 
      \setlength\cC{\value{cb}sp}%
      \setlength\cD{\value{ca}sp}%
      \fi}

    \def\subtractlength{%
     \setcounter{cb}{\cD}%
     \setcounter{ca}{\cC}%
     \addtocounter{cb}{-\cC}}%
    \let\printgcd\relax
    \newcommand{\printgcd}[2]{%
      \setcounter{ca}{#1}\setcounter{cb}{#2}%
      \assignlength
      \@whiledim \cC<\cD Xgcd(\arabic{ca},\arabic{cb}) = \do{%
         \subtractlength\assignlength}%
      \arabic{ca}.}
    \printgcd{144}{272}
:::

\\\@whilesw {#cmd-whilesw}
-----------

You can say `\@whilesw test \fi{body}`. Here `test` is an incomplete
conditional, and the `\fi` token must be explicit. The body is executed
as long as the test is true. See above `` `\whiledo ``
\<doc-w.html\#cmd-whiledo\>\`\_\_ above. This command is defined in the
LaTeX kernel, although not described in the books.

\\\@whilenum {#cmd-whilenum}
------------

You can say `\@whilenum test etc \do{body}`. Here `test` is an
incomplete conditional, of the form number-op-number (where op is one of
\< \> or =) and the `\do` token must be explicit. The body is executed
as long as the test is true. See above `` `\whiledo ``
\<doc-w.html\#cmd-whiledo\>\`\_\_ above. This command is defined in the
LaTeX kernel, although not described in the books.

\\\@whiledim {#cmd-whiledim}
------------

You can say `\@whiledim test etc\do{body}`. Here `test` is an incomplete
conditional, of the form dimen-op-dimen (where op is one of \< \> or =)
and the `\do` token must be explicit. The body is executed as long as
the test is true. See above `` `\whiledo ``
\<doc-w.html\#cmd-whiledo\>\`\_\_ above. This command is defined in the
LaTeX kernel, although not described in the books.

\\widetilde (math accent) {#cmd-widetilde}
-------------------------

The `\widetilde` command puts a tilde accent over a kernel. It is
(currently in *Tralics*) equivalent to `\tilde`. It works only in math
mode. See also the `` `\acute `` \<doc-a.html\#cmd-acute\>\`\_\_
command.

\\widehat (math accent) {#cmd-widehat}
-----------------------

The `\widehat` command puts a hat accent over a kernel. It is (currently
in Tralics) equivalent to `\hat`. It works only in math mode. See also
the `` `\acute `` \<doc-a.html\#cmd-acute\>\`\_\_ command.

\\widowpenalties (internal integer) {#cmd-widowpenalties}
-----------------------------------

This command is an eTeX extension to *Tralics*, that reads or writes a
slot in a dynamically allocated table. The syntax is the following. In a
set context, an equals is read, followed by an integer *n*. If the
integer is positive, then *n* integer values are read and stored,
otherwise the table is cleared. In a get context, an integer *n* is
read, and the result is an integer; if *n* is negative, this is zero, if
*n* is zero it is the length of the table, if *n* is positive it is the
value found in the table (or the last value if *n* is too big). (See
[scanint](doc-s.html#fct-scanint) for details of argument scanning).

The sequence `\widowpenalties=3 101 102 103` reallocates the table
associated to widow penalties, and puts 101, 102 and 103 in it. The
sequence `\the\displaywidowpenalties 0` typesets the value at position 0
in the table, namely 101. The table is not used by *Tralics*. In the
code that follows, the macro `\bad` is not called.

::: {.container .ltx-source}
    \interlinepenalties=3 1 2 3
    \clubpenalties=3 11 12 13
    \widowpenalties=3 101 102 103
    \displaywidowpenalties=3 1001 1002 1003
    \widowpenalties= -1
    \edef\foo{%
    \the\interlinepenalties 1
    \the\clubpenalties\interlinepenalties2
    \the\displaywidowpenalties -1
    \the\displaywidowpenalties 0
    \the\displaywidowpenalties 4
    \the\widowpenalties 0}
    \def\xfoo{1120310030}
    \ifx\foo\xfoo\else\bad\fi
:::

\\widowpenalty (internal integer) {#cmd-widowpenalty}
---------------------------------

When you say `\widowpenalty=100`, then TeX will use 100 as penalty for a
lonely line at the top of a page (line not followed by an equation) when
it computes optimal page breaks. Unused by *Tralics*. (See
[scanint](doc-s.html#fct-scanint) for details of argument scanning).

\\\@width {#cmd-width}
---------

This command expands to `width`. Do not modify it.

\\widthof {#cmd-widthof}
---------

This command is defined by the \`calc\' package but not implemented in
*Tralics*.

\\wlog {#cmd-wlog}
------

The command `\wlog` behaves like `` `\write-1 `` \<\#cmd-write\>\`\_\_.
This means that the command reads a list of tokens, and prints it
(expanded) to the transcript file.

\\wp (math symbol) {#cmd-wp}
------------------

The `\wp` command is valid only in math mode. It generates a
miscellaneous symbol: `<mi>&wp;</mi>` (Unicode U+2118, ℘). See
description of the `` `\ldots `` \<doc-l.html\#cmd-ldots\>\`\_\_
command.

\\wr (math symbol) {#cmd-wr}
------------------

The `\wr` command is valid only in math mode. It generates a binary
operator: `<mo>&wr;</mo>`, (Unicode U+2240, ≀). See description of the
`` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

wrapfigure, wraptable (environment) {#env-wrapfigure}
-----------------------------------

These two environments are extensions of `figure` and `table`.

::: {.container .ltx-source}
    \begin{wrapfigure}[12]{r}[34pt]{5cm} FIG \end{wrapfigure}
    \begin{wraptable}[12]{r}[34pt]{5cm} TABLE \end{wraptable}
    \begin{wrapfigure}{r}{5cm} FIG \end{wrapfigure}
    \begin{wraptable}{r}{5cm} TABLE \end{wraptable}
:::

::: {.container .xml_out}
    <figure id-text='2' id='uid48' width='5cm' overhang='34pt' place='r' narrow='12'>
      <p rend='center'>FIG</p>
    </figure>
    <table rend='display' id-text='1' id='uid49' width='5cm' overhang='34pt' place='r' narrow='12'>
      <unexpected>TABLE</unexpected>
    </table>
    <figure id-text='3' id='uid50' width='5cm' place='r'>
      <p rend='center'>FIG</p>
    </figure>
    <table rend='display' id-text='2' id='uid51' width='5cm' place='r'>
      <unexpected>TABLE</unexpected>
    </table>
:::

\\write {#cmd-write}
-------

After `\write` comes a number and a general text (see the
[scanint](doc-s.html#fct-scanint) command for details of parsing) the
number and [scantoks](doc-s.html#fct-scantoks) for the other argument).
The effect is to write the second argument in the file specified by the
first argument. See `` `\openout `` \<doc-o.html\#cmd-openout\>\`\_\_
for further information).
