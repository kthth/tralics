All commands, alphabetic order; letter B
========================================

| This page contains the description of the following commands
  [\\b](#cmd-b), [\\backepsilon](#cmd-backepsilon),
  [\\backmatter](#cmd-backmatter), [\\backprime](#cmd-backprime),
  [\\backsim](#cmd-backsim), [\\backsimeq](#cmd-backsimeq),
  [\\backslash](#cmd-backslash), [\\badness](#cmd-badness),
  [\\bar](#cmd-bar), [\\barnodeconnect](#cmd-barnodeconnect),
  [\\baro](#cmd-baro), [\\barwedge](#cmd-barwedge),
  [\\baselineskip](#cmd-baselineskip), [\\batchmode](#cmd-batchmode),
  [\\bauthors](#cmd-bauthors), [\\Bbbk](#cmd-bbbk),
  [\\because](#cmd-because), [\\beditors](#cmd-bauthors),
  [\\begin](#cmd-begin), [\\begingroup](#cmd-begingroup),
  [\\beginL](#cmd-beginL), [\\beginR](#cmd-beginL),
  [\\\@begintheorem](#cmd-begintheorem),
  [\\belowdisplayskip](#cmd-belowdisplayskip),
  [\\belowdisplayshortskip](#cmd-belowdisplayshortskip),
  [\\beta](#cmd-beta), [\\beth](#cmd-beth), [\\between](#cmd-between),
  [\\bezier](#cmd-bezier), [\\bf](#cmd-bf), [\\bfseries](#cmd-bfseries),
  [\\bgroup](#cmd-bgroup), [\\bibitem](#cmd-bibitem),
  [\\bibitem\@empty](#cmd-bibitem-empty),
  [\\bibliography](#cmd-bibliography),
  [\\bibliographystyle](#cmd-bibliographystyle), [\\big](#cmd-big),
  [\\Big](#cmd-big), [\\bigbox](#cmd-bigbox),
  [\\bigbreak](#cmd-bigbreak), [\\bigcap](#cmd-bigcap),
  [\\bigcirc](#cmd-bigcirc), [\\bigcircle](#cmd-bigcircle),
  [\\bigcup](#cmd-bigcup), [\\bigcurlyvee](#cmd-bigcurlyvee),
  [\\bigcurlywedge](#cmd-bigcurlywedge), [\\Bigg](#cmd-big),
  [\\bigg](#cmd-big), [\\Biggl](#cmd-bigl), [\\biggl](#cmd-bigl),
  [\\Biggm](#cmd-bigm), [\\biggm](#cmd-bigm), [\\Biggr](#cmd-bigr),
  [\\biggr](#cmd-bigr), [\\biginterleave](#cmd-biginterleave),
  [\\Bigl](#cmd-bigl), [\\bigl](#cmd-bigl), [\\Bigm](#cmd-bigm),
  [\\bigm](#cmd-bigm), [\\bignplus](#cmd-bignplus),
  [\\bigodot](#cmd-bigodot), [\\bigoplus](#cmd-bigoplus),
  [\\bigotimes](#cmd-bigotimes), [\\bigparallel](#cmd-bigparallel),
  [\\Bigr](#cmd-bigr), [\\bigr](#cmd-bigr), [\\bigskip](#cmd-bigskip),
  [\\bigskipamount](#cmd-bigskipamount), [\\bigsqcap](#cmd-bigsqcap),
  [\\bigsqcup](#cmd-bigsqcup), [\\bigstar](#cmd-bigstar),
  [\\bigtriangledown](#cmd-bigtriangledown),
  [\\bigtriangleup](#cmd-bigtriangleup), [\\biguplus](#cmd-biguplus),
  [\\bigvee](#cmd-bigvee), [\\bigwedge](#cmd-bigwedge),
  [\\binampersand](#cmd-binampersand),
  [\\bindnasrepma](#cmd-bindnasrepma), [\\binom](#cmd-binom),
  [\\binoppenalty](#cmd-binoppenalty),
  [\\blacklozenge](#cmd-blacklozenge),
  [\\blacksquare](#cmd-blacksquare),
  [\\blacktriangle](#cmd-blacktriangle),
  [\\blacktriangledown](#cmd-blacktriangledown),
  [\\blacktriangleleft](#cmd-blacktriangleleft),
  [\\blacktriangleright](#cmd-blacktriangleright), [\\bmod](#cmd-bmod),
  [\\bodytext](doc-h.html#cmd-html), [\\boolean](#cmd-boolean),
  [\\bot](#cmd-bot), [\\botfigrule](#cmd-botfigrule),
  [\\botmark](#cmd-botmark), [\\botmarks](#cmd-botmarks),
  [\\bottom](#cmd-bottom), [\\bottomfraction](#cmd-bottomfraction),
  [bottomnumber](#cmd-bottomnumber), [\\bowtie](#cmd-bowtie),
  [\\Box](#cmd-Cbox), [\\box](#cmd-box), [\\boxast](#cmd-boxast),
  [\\boxbox](#cmd-boxbox), [\\boxbslash](#cmd-boxbslash),
  [\\boxcircle](#cmd-boxcircle), [\\boxdot](#cmd-boxdot),
  [\\boxed](#cmd-boxed), [\\boxempty](#cmd-boxempty),
  [\\boxmaxdepth](#cmd-boxmaxdepth), [\\boxminus](#cmd-boxminus),
  [\\boxplus](#cmd-boxplus), [\\boxslash](#cmd-boxslash),
  [\\boxtimes](#cmd-boxtimes), [\\bpers](#cmd-bpers),
  [\\bprime](#cmd-bprime), [\\brace](#cmd-brace),
  [\\bracevert](#cmd-bracevert), [\\brack](#cmd-brace),
  [\\break](#cmd-break), [\\breve](#cmd-breve),
  [\\brokenpenalty](#cmd-brokenpenalty), [\\bullet](#cmd-bullet),
  [\\Bumpeq](#cmd-Bumpeq), [\\bye](#cmd-bye),
| and environments [Beqnarray](#env-Beqnarray), [body](#env-body).

------------------------------------------------------------------------

\\b {#cmd-b}
---

The `\b` command generates a bar-under accent. The translation of

::: {.container .ltx-source}
    \b B \b b \b D \b d \b h \b K \b k \b L \b l
    \b N \b n \b R \b r \b T \b t \b Z \b z
:::

is

::: {.container .xml_out}
    &#7686; &#7687; &#7694; &#7695; &#7830; &#7732; &#7733; &#7738; &#7739;
    &#7752; &#7753; &#7774; &#7775; &#7790; &#7791; &#7828; &#7829;
:::

Preview: ![ring below accent](/img/img_97.png){.vc .vc} HTML characters
Ḇ ḇ Ḏ ḏ ẖ Ḵ ḵ Ḻ ḻ Ṉ ṉ Ṟ ṟ Ṯ ṯ Ẕ ẕ

\\backepsilon (math symbol) {#cmd-backepsilon}
---------------------------

The `\backepsilon` command is valid only in math mode. It generates the
reversed epsilon character `<mo>&backepsilon;</mo>` (Unicode 3F6, ϶).

\\backmatter {#cmd-backmatter}
------------

A command to be used after the main matter in a book. See description of
the `` `\mainmatter `` \<doc-m.html\#cmd-mainmatter\>\`\_\_ command.

\\backprime (math symbol) {#cmd-backprime}
-------------------------

The `\backprime` command is valid only in math mode. It generates the
reversed prime character `<mo>&backprime;</mo>` (Unicode 2035, ‵).

\\backsim (math symbol) {#cmd-backsim}
-----------------------

The `\backsim` command is valid only in math mode. It generates the
reversed tilde character `<mo>&backsim;</mo>` (Unicode 223D, ∽).

\\backsimeq (math symbol) {#cmd-backsimeq}
-------------------------

The `\backsimeq` command is valid only in math mode. It generates the
reversed tilde with equals character `<mo>&backsimeq;</mo>` (Unicode
22CD, ⋍).

\\backslash (math symbol) {#cmd-backslash}
-------------------------

The `\backslash` command gives a backslash. It is valid only in math
mode. Use `\textbackslash` for a backslash in text mode. Translation is
`<mo>&Backslash;</mo>` (Unicode 2216, ∖). See also description of the
`` `\smallint `` \<doc-s.html\#cmd-smallint\>\`\_\_ command.

\\badness {#cmd-badness}
---------

In TeX, the variable `\badness` contains the badness of the last box. In
*Tralics*, you can say `\count25=\badness` if you want to put zero into
count register 25, or you can say `\the\badness` if you want a zero
digit.

\\bar {#cmd-bar}
-----

The `\bar` command puts a bar accent over a kernel. It works only in
math mode; use the `` `\= `` \<doc-symbols.html\>[\_\_ command outside
math mode. See also the ]{.title-ref}`\acute`
\<doc-a.html\#cmd-acute\>\`\_\_ command.

\\baro (math symbol) {#cmd-baro}
--------------------

The `\baro` command is valid in math mode only, it translates to
`<mo>&ovbar;</mo>` (Unicode 233D, ⌽), it is a vertical bar in a circle.

\\barwedge (math symbol) {#cmd-barwedge}
------------------------

The `\barwedge` command is valid in math mode only, it translates to
`<mo>&#x22BC;</mo>` (Unicode 22BC, ⊼).

\\barnodeconnect {#cmd-barnodeconnect}
----------------

The command `\barnodeconnect[d]{F}{T}` connects nodes F and T using a
bar of depth d. See `` `\abarnodeconnect ``
\<doc-a.html\#cmd-abarnodeconnect\>\`\_\_ command for syntax and usage.

\\baselineskip (rubber length) {#cmd-baselineskip}
------------------------------

You can say `\baselineskip=10pt plus 2pt minus 3pt`. This explains to
TeX that it should put 10pt (maybe up to 2pt more, maybe up to 3pt less)
of glue between the baselines of two consecutive lines in a paragraph
(this may depend on `\lineskiplimit`). Unused by *Tralics*. (See
[scanglue](doc-s.html#fct-scanglue) for details of argument scanning).

\\baselinestretch {#cmd-baselinestretch}
-----------------

This commands expands to 1. (See TLC2, section 3.1.13).

\\batchmode {#cmd-batchmode}
-----------

You can prefix the command `\batchmode` with `\global`. Nothing happens,
since batch-mode is the only interaction mode.

\\bauthors, \\beditors (Tralics command) {#cmd-bauthors}
----------------------------------------

The two commands `\bauthors` and `\beditors` translate their argument,
and put the result is a element of the same name. See `` `\citation ``
\<doc-c.html\#cmd-citation\>[\_\_ for details. These commands are
produced when translating the bibliography, in this case the argument is
a list of ]{.title-ref}[bpers]{.title-ref}\` commands.

\\Bbbk {#cmd-bbbk}
------

The `\Bbbk` command produces a blackboard k, it is the same as
`\mathbb{k}`.

\\because (math symbol) {#cmd-because}
-----------------------

The `\because` command is valid in math mode only, it translates to
`<mo>&because;</mo>` (Unicode U+2235, ∵).

\\begin {#cmd-begin}
-------

You can say something like `\begin{something} some code \end{thesame}`.
The result of this is to translate the code inside a group. Moreover,
some specific action is done at the beginning and the end of the
environment. For instance `\something` is called first, and
`\endthesame` is called at the end.

The documentation says that `\begin{em} some code \end{em}` is the same
as `{\em some code}`. Practically, this means that `\end{thesame}`
produces nothing (in particular no error), if `\endthesame` is not
defined.

The argument to `\begin` and `\end` is converted to a command name via
`\csname`, hence macros are expanded. If you say
`\def\xx#1{}\begin{\xx}`, you get the following LateX error: *! Missing
\\endcsname inserted. \<to be read again\> \\relax*. This is because the
command `\xx` reads the `\endcsname` marker, and checking whether the
environment is defined inserts a `\relax`. For the same example
*Tralics* says *End of data reached while expecting \\endcsname*, and in
the case of `\begin{abc\par cde}`, the error reads *Invalid token \\par
found while scanning \\begin*. No error is signaled in the case
`\begin{abc\endcsname cde}`. In both these cases, the environment is
named "abc" and the superfluous tokens `cde` are ignored.

If you say: `\begin{\em} ... \end{\em}`, LaTeX complains with *! Missing
\\endcsname inserted.* This is because `\em` is a robust command (one
for which expansion can be delayed); it expands to `\protect` which
cannot be expanded (the meaning of `\protect` depends on the context).

If you say `\def\FOO{foo} \begin{\FOO}\end{foo}` you get the following
error: *! LaTeX Error: \\begin{foo} on input line 22 ended by
\\end{foo}.* This is because the names are different `\FOO` versus
`foo`, and the error message is printed via `\errmessage` that expands
everything. No error is signaled by *Tralics* in this case. Note the
funny error for `\begin{a}\end{a}`, because `\a` tries to fetch an
accent: *! LaTeX Error: Command \\end unavailable in encoding T1.* Note
that `\begin{}\end{}` gives infinite recursion in LaTeX, this is a
special case in *Tralics*. The commands `\begin{group} \end{group}` give
two errors: first *Undefined environment group* then *Extra \\endgroup
found in unclosed environment group*.

Historical note. Before 2.13.3, only characters were allowed in an
environment name (nothing is expanded). Since version 2.10, spaces are
allowed in an environment name. Since version 2.14, environment names
can have less than two letters.

Environments should nest properly. What this means is unclear to me. You
may say `\newenvironment{foo} {\begin{bar}} {\end{bar}}` followed by
`\begin{foo} ... \end{foo}`. When the `\end` command is seen, the
current environment is \`bar\' and the argument is \`foo\': these names
are not the same. However `\endfoo` will call `\end{bar}` and close the
other environment. As a consequence, only a posteriori tests can be
made. This makes error recovery unclear.

\\\@begintheorem {#cmd-begintheorem}
----------------

Private Tralics command.

\\beginL, \\beginR {#cmd-beginL}
------------------

These commands are ε-TeX extensions that indicate the start of a
left-to-right or right-to-left region; they are ignored by *Tralics*.

\\begingroup {#cmd-begingroup}
------------

The `\begingroup` command defines a semi-simple group, that must be
terminated by `\endgroup`. In some cases a construct like
`\begingroup\it x\endgroup` is exactly the same as `{\it x}`, or as
`\bgroup\it x\egroup`.

\\belowdisplayshortskip (rubber length) {#cmd-belowdisplayshortskip}
---------------------------------------

You can say `\belowdisplayshortskip=10pt plus 2pt minus 3pt`. The
`\belowdisplayshortskip` register contains a skip value that TeX puts
after a short display. The value is unused by *Tralics*. (See
[scanglue](doc-s.html#fct-scanglue) for details of argument scanning).
(See `` `\predisplaysize `` \<doc-p.html\#cmd-predisplaysize\>\`\_\_ for
further details).

\\belowdisplayskip (rubber length) {#cmd-belowdisplayskip}
----------------------------------

You can say `\belowdisplayskip=10pt plus 2pt minus 3pt`. The
`\belowdisplayskip` register contains a skip value that TeX puts after a
display. The value is unused by *Tralics*. (See
[scanglue](doc-s.html#fct-scanglue) for details of argument scanning).
(See `` `\predisplaysize `` \<doc-p.html\#cmd-predisplaysize\>\`\_\_ for
further details).

Beqnarray, Beqnarray\* (environments) {#env-Beqnarray}
-------------------------------------

The fancybox package provides a variant of the `eqnarray` environment
that can be used inside a box; the documentation provides this example:

::: {.container .ltx-source}
:

    \fbox{%
      \begin{Beqnarray*}
        x &=&y\\
        y& >& x\\
        \int_4^5 f(x)dx &=&\sum_{i\in F} x_i
      \end{Beqnarray*}
    }
:::

Here is the translation. The math formula consists in a table with three
rows, omitted here.

::: {.container .xml_out}
    <fbox rend='boxed'>
      <formula textype='Beqnarray*' type='display'>
        <math mode='display' xmlns='http://www.w3.org/1998/Math/MathML'>
         <mtable displaystyle='true'>
           <mtr>...</mtr><mtr>...</mtr><mtr>...</mtr>
         </mtable>
        </math>
      </formula>
    </fbox>
:::

\\beta (math character) {#cmd-beta}
-----------------------

The `\beta` command is valid only in math mode. It generates a Greek
letter: `<mi>&beta;</mi>` (Unicode U+3B2, β) that renders like
![\$beta\$](/img/img_beta.png){.vc .vc}. See description of the
`` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\beth (math character) {#cmd-beth}
-----------------------

The `\beth` command is valid only in math mode. It generates a Hebrew
letter: `<mi>&beth;</mi>` (Unicode U+2136, ℶ).

\\between (math symbol) {#cmd-between}
-----------------------

The `\between` command is valid only in math mode. It generates a
symbol: `<mi>&between;</mi>` (Unicode U+226C, ≬).

\\bezier {#cmd-bezier}
--------

This is like `\qbezier` but it has a first required argument instead of
optional. See the `` `\qbezier `` \<doc-q.html\#cmd-qbezier\>\`\_\_
command.

\\bf {#cmd-bf}
----

The `\bf` command is equivalent to `\normalfont\bfseries`. In other
words, it selects a font of roman family, bold series and upright shape.
For an example of fonts, see `` `\rm `` \<doc-r.html\#cmd-rm\>\`\_\_.

\\bfseries {#cmd-bfseries}
----------

The `\bfseries` command changes the series of the current font to a bold
face series. For an example of fonts, see `` `\rm ``
\<doc-r.html\#cmd-rm\>\`\_\_.

\\bgroup {#cmd-bgroup}
--------

The `\bgroup` command is an open brace of catcode 1. For an example see
[catcode1](doc-symbols.html#catcode1).

\\bibitem {#cmd-bibitem}
---------

This command takes two arguments, the first being optional. Translation
of `\bibitem [toto] {titi}` is `<bibitem id='bid17' bib-key='toto'/>`.
The element will have an id and a bib-key attribute that comes from the
optional argument. If you say `\cite{titi}`, this will create a
reference to this bibitem element. (See `` `\XMLsolvecite ``
\<doc-x.html\#cmd-XMLsolvecite\>[\_\_ for more details). Note that the
equivalent of ]{.title-ref}[noindent]{.title-ref}\` is executed; this
implies that a new paragraph is started. \[Translation changed in
version 2.12.1\]

\\<bibitem@empty> (Tralics command) {#cmd-bibitem-empty}
-----------------------------------

You can say `\bibitem@empty{foo}`, this will signal an error because the
command has been withdrawn.

\\bibliography {#cmd-bibliography}
--------------

The `\bibliography` command takes as argument a list of file-names from
which bibtex takes the bibliographical entries. In *Tralics*, this
command has as side-effect to load the bibliography, i.e. the bbl file.
In the current version, this file is created by *Tralics* and not by an
external program.

\\bibliographystyle {#cmd-bibliographystyle}
-------------------

When you say `\bibliographystyle{alpha}`, this tells bibtex to use the
alpha.bst file. In the current version, *Tralics* does not call bibtex,
and the bibliography is handled, independently of the argument of this
command. In a future version, something will be done.

\\big, \\Big, \\bigg, \\Bigg {#cmd-big}
----------------------------

The `\big` declaration is valid only in math mode. It is ignored unless
what follows is a character that can become bigger in the vertical
dimension. In some cases, `\big` is replaced by a `\left` or `\right`
command. Hence all four commands `\big \Big \bigg \Bigg` produce the
same result. If you say `\big(`, the result is an opening delimiter,
that can be converted into `\left(`; if you say `\bigl)`, the result is
also an opening delimiter, because the command says so. If you say
`\bigm)`, you get a middle delimiter, that can produce a `\middle(` (the
`\middle` command is not yet implemented). For an example, see
`` `\mathord `` \<doc-m.html\#cmd-mathord\>\`\_\_.

\\bigl, \\Bigl, \\biggl, \\Biggl {#cmd-bigl}
--------------------------------

See `\big` above. This is a left (opening) delimiter.

\\bigr, \\Bigr, \\biggr, \\Biggr {#cmd-bigr}
--------------------------------

See `\big` above. This is a right (closing) delimiter.

\\bigm, \\Bigm, \\biggm, \\Biggm {#cmd-bigm}
--------------------------------

See `\big` above. This is a middle (neither opening nor closing)
delimiter.

\\bigbox (math symbol) {#cmd-bigbox}
----------------------

The `\bigbox` command is valid only in math mode. It is an alias for
`` `\square `` \<doc-s.html\#cmd-square\>[\_\_. Translation is
]{.title-ref}[\<mo\>&square;\</mo\>]{.title-ref}\` (Unicode U+25A1, □)

\\bigbreak {#cmd-bigbreak}
----------

In *Tralics*, the `\bigbreak` command is the same as `\par`. In LaTeX,
it makes also sure that the space between the two paragraphs is at least
`\bigskipamount`, by calling `\bigskip` if necessary; not implemented in
*Tralics*.

\\bigcap (math symbol) {#cmd-bigcap}
----------------------

The `\bigcap` command is valid only in math mode. Its translation is a
variable-sized symbol (used for set intersection): `<mo>&bigcap;</mo>`
(Unicode U+22C2, ⋂) that renders like
![\$bigcap\$](/img/img_t_bigcap.png). For an example see the `` `\sum ``
\<doc-s.html\#cmd-sum\>\`\_\_ command.

\\bigcirc (math symbol) {#cmd-bigcirc}
-----------------------

The `\bigcirc` command is valid only in math mode. It generates a binary
operator (big circle): `<mo>&bigcirc;</mo>` (Unicode U+25EF, ◯) that
renders like ![\$bigcirc\$](/img/img_t_bigcirc.png). See description of
the `` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\bigcircle {#cmd-bigcircle}
-----------

The `\bigcircle` command is defined by the curves package. See
`` `\arc `` \<doc-a.html\#cmd-arc\>\`\_\_.

\\bigcup (math symbol) {#cmd-bigcup}
----------------------

The `\bigcup` command is valid only in math mode. Its translation is a
variable-sized symbol (used for set union): `<mo>&bigcup;</mo>` (Unicode
U+22C3, ⋃) that renders like ![\$bigcup\$](/img/img_t_bigcup.png). For
an example see the `` `\sum `` \<doc-s.html\#cmd-sum\>\`\_\_ command.

\\bigcurlyvee (math symbol) {#cmd-bigcurlyvee}
---------------------------

The `\bigcurlywedge` command is valid only in math mode. It is an alias
to `` `\curlyvee `` \<doc-c.html\#cmd-curlyvee\>\`\_\_.

\\bigcurlywedge (math symbol) {#cmd-bigcurlywedge}
-----------------------------

The `\bigcurlywedge` command is valid only in math mode. It is an alias
to `` `\curlywedge `` \<doc-c.html\#cmd-curlywedge\>\`\_\_.

\\bignplus (math symbol) {#cmd-bignplus}
------------------------

The `\bignplus` command is valid only in math mode. It is an alias to
`\nplus`. **Note** these two commands are described but not implemented.

\\biginterleave (math symbol) {#cmd-biginterleave}
-----------------------------

The `\biginterleave` command is valid only in math mode. It is an alias
to `` `\interleave `` \<doc-i.html\#cmd-interleave\>\`\_\_.

\\bigodot (math symbol) {#cmd-bigodot}
-----------------------

The `\bigodot` command is valid only in math mode. Its translation is a
variable-sized symbol (dot in a circle): `<mo>&bigodot;</mo>` (Unicode
U+2A00, ⨀) that renders like ![\$bigodot\$](/img/img_t_bigodot.png). For
an example see the `` `\sum `` \<doc-s.html\#cmd-sum\>\`\_\_ command.

\\bigoplus (math symbol) {#cmd-bigoplus}
------------------------

The `\bigoplus` command is valid only in math mode. Its translation is a
variable-sized symbol (plus in a circle): `<mo>&bigoplus;</mo>` (Unicode
U+2A01, ⨁) that renders like ![\$bigoplus\$](/img/img_t_bigoplus.png).
For an example see the `` `\sum `` \<doc-s.html\#cmd-sum\>\`\_\_
command.

\\bigotimes (math symbol) {#cmd-bigotimes}
-------------------------

The `\bigotimes` command is valid only in math mode. Its translation is
a variable-sized symbol (times in a circle): `<mo>&bigotimes;</mo>`
(Unicode U+2A02, ⨂) that renders like
![\$bigotimes\$](/img/img_t_bigotimes.png). For an example see the
`` `\sum `` \<doc-s.html\#cmd-sum\>\`\_\_ command.

\\bigparallel (math symbol) {#cmd-bigparallel}
---------------------------

The `\bigparallel` command is valid only in math mode. It is an alias to
`` `\parallel `` \<doc-p.html\#cmd-parallel\>\`\_\_.

\\bigskip {#cmd-bigskip}
---------

The `\bigskip` command is like the `` `\smallskip ``
\<doc-s.html\#cmd-smallskip\>[\_\_ command. (see also the
]{.title-ref}`\vskip` \<doc-v.html\#cmd-vskip\>\`\_\_ command).

\\bigskipamount (rubber length) {#cmd-bigskipamount}
-------------------------------

This is defined by *Tralics* in the same way as in LaTeX, but is unused,
see `` `\smallskip `` \<doc-s.html\#cmd-small-skip\>\`\_\_

\\bigsqcap (math symbol) {#cmd-bigsqcap}
------------------------

The `\bigsqcap` command is valid only in math mode. Its translation is a
variable-sized symbol (square cap): `<mo>&sqcap;</mo>` (Unicode U+2293,
⊓). For an example see the `` `\sum `` \<doc-s.html\#cmd-sum\>\`\_\_
command.

\\bigsqcup (math symbol) {#cmd-bigsqcup}
------------------------

The `\bigsqcup` command is valid only in math mode. Its translation is a
variable-sized symbol (square cup): `<mo>&bigsqcup;</mo>` (Unicode
U+2A06, ⨆). For an example see the `` `\sum ``
\<doc-s.html\#cmd-sum\>\`\_\_ command.

\\bigstar (math symbol) {#cmd-bigstar}
-----------------------

The `\bigstar` command is valid only in math mode. Its translation is
`<mo>&bigstar;</mo>` (Unicode U+2605, ★).

\\bigtriangledown (math symbol) {#cmd-bigtriangledown}
-------------------------------

The `\bigtriangledown` command is valid only in math mode. It generates
a binary operator. Looks like a reversed `\Delta`:
`<mo>&bigtriangledown;</mo>` (Unicode U+25BD, ▽) that renders like
![\$bigtriangledown\$](/img/img_t_bigtriangledown.png). See description
of the `` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\bigtriangleup (math symbol) {#cmd-bigtriangleup}
-----------------------------

The `\bigtriangleup` command is valid only in math mode. It generates a
binary operator. Looks like a `\Delta`: `<mo>&bigtriangleup;</mo>`
(Unicode U+25B3, △) that renders like
![\$bigtriangleup\$](/img/img_t_bigtriangleup.png). See description of
the `` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\biguplus (math symbol) {#cmd-biguplus}
------------------------

The `\biguplus` command is valid only in math mode. Its translation is a
variable-sized symbol. It is like a plus in a cup: `<mo>&biguplus;</mo>`
(Unicode U+228E, ⊎) that renders like
![\$biguplus\$](/img/img_t_biguplus.png). For an example see the
`` `\sum `` \<doc-s.html\#cmd-sum\>\`\_\_ command.

\\bigvee (math symbol) {#cmd-bigvee}
----------------------

The `\bigvee` command is valid only in math mode. Its translation is a
variable-sized symbol. It looks like a big V: `<mo>&bigvee;</mo>`
(Unicode U+22C1, ⋁) that renders like
![\$bigvee\$](/img/img_t_bigvee.png). For an example see the `` `\sum ``
\<doc-s.html\#cmd-sum\>\`\_\_ command.

\\bigwedge (math symbol) {#cmd-bigwedge}
------------------------

The `\bigwedge` command is valid only in math mode. Its translation is a
variable-sized symbol. It looks like a big reversed V:
`<mo>&bigwedge;</mo>` (Unicode U+22C0, ⋀) that renders like
![bigwedge](/img/img_t_bigwedge.png). For an example see the `` `\sum ``
\<doc-s.html\#cmd-sum\>\`\_\_ command.

\\binampersand (math symbol) {#cmd-binampersand}
----------------------------

The `\binampersand` command is valid only in math mode. Its translation
is `<mo>&amp;</mo>`.

\\bindnasrepma (math symbol) {#cmd-bindnasrepma}
----------------------------

The `\bindnasrepma` command is valid only in math mode. Its translation
is `<mo>&#x214B;</mo>` ⅋

\\binom {#cmd-binom}
-------

The `\binom` command is valid in math mode only. It could be defined as
`\def\binom{\genfrac()\z@{}}`. The translation is a `<mfence>` element,
containing a `<mfrac>` element. The two arguments of the `\binom`
command are typeset one above the other, with parentheses around. There
are two variants `\dbinom` `\tbinom` that control the size of the
arguments. Note that `\left(\right)` produces bigger parentheses than
`\genfrac`. Example.

::: {.container .ltx-source}
:

    \def\n{\mathchoice{a}{b}{c}{d}}
    $$\binom{\frac{\n+m}{2}} \n \quad
    \tbinom{\frac{\n+m}{2}} \n \quad
    \dbinom{\frac{\n+m}{2}} \n\qquad
    {}^{\binom{\frac{\n+m}{2}} \n \quad
    \tbinom{\frac{\n+m}{2}} \n \quad
    \dbinom{\frac{\n+m}{2}} \n}$$
:::

This is the translation. Comments were not generated by *Tralics*

::: {.container .xml_out}
    <formula type='display'>
     <math xmlns='http://www.w3.org/1998/Math/MathML'>
      <mrow><mfenced open='(' close=')'>
       <!--\binom{\frac{\n+m}{2}} \n -->
       <mfrac linethickness='0.0pt'>
        <mfrac>
         <mrow><mi>c</mi><mo>+</mo><mi>m</mi></mrow> <mn>2</mn></mfrac> 
         <mi>b</mi>
        </mfrac>
       </mfenced> 
       <mspace width='1.em'/>
       <!--\tbinom{\frac{\n+m}{2}} \n -->
       <mfenced open='(' close=')'>
        <mstyle scriptlevel='0' displaystyle='false'>
         <mfrac linethickness='0.0pt'>
          <mfrac><mrow><mi>d</mi><mo>+</mo><mi>m</mi></mrow> <mn>2</mn></mfrac>
          <mi>c</mi>
         </mfrac>
        </mstyle> 
       </mfenced>
       <mspace width='1.em'/>
       <!--\dbinom{\frac{\n+m}{2}} \n -->
       <mfenced open='(' close=')'>
        <mstyle scriptlevel='0' displaystyle='true'>
         <mfrac linethickness='0.0pt'>
          <mfrac><mrow><mi>c</mi><mo>+</mo><mi>m</mi></mrow> <mn>2</mn></mfrac> 
          <mi>b</mi>
         </mfrac>
        </mstyle>
       </mfenced>
       <mspace width='2.em'/>
       <msup>
        <mrow></mrow> 
        <mrow>
         <!-- {}^\binom{\frac{\n+m}{2}} \n -->
         <mfenced open='(' close=')'>
          <mfrac linethickness='0.0pt'>
           <mfrac><mrow><mi>d</mi><mo>+</mo><mi>m</mi></mrow> <mn>2</mn></mfrac> 
           <mi>d</mi>
          </mfrac>
         </mfenced>
         <mspace width='1.em'/>
         <!-- {}^\tbinom{\frac{\n+m}{2}} \n -->
         <mfenced open='(' close=')'>
          <mstyle scriptlevel='0' displaystyle='false'>
           <mfrac linethickness='0.0pt'>
            <mfrac><mrow><mi>d</mi><mo>+</mo><mi>m</mi></mrow> <mn>2</mn></mfrac> 
            <mi>c</mi>
           </mfrac>
          </mstyle>
         </mfenced>
         <mspace width='1.em'/>
         <!--{}^\dbinom{\frac{\n+m}{2}} \n -->
         <mfenced open='(' close=')'>
          <mstyle scriptlevel='0' displaystyle='true'>
           <mfrac linethickness='0.0pt'>
            <mfrac><mrow><mi>c</mi><mo>+</mo><mi>m</mi></mrow> <mn>2</mn></mfrac>
            <mi>b</mi>
           </mfrac>
          </mstyle> 
         </mfenced>
        </mrow> 
       </msup>
      </mrow> 
     </math>
    </formula>
:::

Preview: ![three variants of binom](/img/img_55.png) (See also
[here](mml_ex.html#binom)).

\\binoppenalty (integer parameter) {#cmd-binoppenalty}
----------------------------------

If you say `\binoppenalty=26`, then TeX will use 26 as penalty for line
break in a math formula after a binary operator (like +). This parameter
is ignored by *Tralics* (note that, in the current implementation,
`$a+b$` and `$a\mathrel+b$` are identically translated; it is hence
impossible to decide whether the plus is binary or not). (See
[scanint](doc-s.html#fct-scanint) for details of argument scanning).

\\blacklozenge (math symbol) {#cmd-blacklozenge}
----------------------------

The `\blacklozenge` command is valid only in math mode. Its translation
is `<mo>&blacklozenge</mo>` (Unicode U+29EB, ⧫).

\\blacksquare (math symbol) {#cmd-blacksquare}
---------------------------

The `\blacksquare` command is valid only in math mode. Its translation
is `<mo>&blacksquare;</mo>` (Unicode U+25AA, ▪).

\\blacktriangle (math symbol) {#cmd-blacktriangle}
-----------------------------

The `\blacktriangle` command is valid only in math mode. Its translation
is `<mo>&blacktriangle;</mo>` (Unicode U+25B4, ▴)

\\blacktriangledown (math symbol) {#cmd-blacktriangledown}
---------------------------------

The `\blacktriangledown` command is valid only in math mode. Its
translation is `<mo>&blacktriangledown;</mo>` (Unicode U+25BE, ▾).

\\blacktriangleleft (math symbol) {#cmd-blacktriangleleft}
---------------------------------

The `\blacktriangleleft` command is valid only in math mode. Its
translation is `<mo>&blacktriangleleft;</mo>` (Unicode +U25C2, ◂).

\\blacktriangleright (math symbol) {#cmd-blacktriangleright}
----------------------------------

The `\blacktriangleright` command is valid only in math mode. Its
translation is `<mo>&blacktriangleright;</mo>` (Unicode U+25B8, ▸).

\\bmod {#cmd-bmod}
------

This command is one the 4 modulo commands. Here is an example (TLC2,
8-4-7, first half).

::: {.container .ltx-source}
    \begin{align*}
    u& \equiv v+1 \mod{n^2} \\
    u& \equiv v+1 \bmod{n^2} \\
    u&   =    v+1 \pmod{n^2} \\
    u&   =    v+1 \pod{n^2} \\
    \end{align*}
:::

This is the translation

::: {.container .xml_out}
    <formula id-text='mid1' id='uid1' type='display'>
     <math mode='display' xmlns='http://www.w3.org/1998/Math/MathML'>
      <mtable displaystyle='true'>
       <mtr>
        <mtd columnalign='right'><mi>u</mi></mtd>
        <mtd columnalign='left'><mrow><mo>&equiv;</mo><mi>v</mi><mo>+</mo><mn>1</mn>
         <mspace width='3.33333pt'/><mo form='prefix'>mod</mo><mspace width='0.277778em'/> 
         <msup><mi>n</mi> <mn>2</mn> </msup></mrow></mtd>
       </mtr>
       <mtr>
        <mtd columnalign='right'><mi>u</mi></mtd>
        <mtd columnalign='left'><mrow><mo>&equiv;</mo><mi>v</mi><mo>+</mo><mn>1</mn>
         <mspace width='0.277778em'/><mo form='prefix'>mod</mo><mspace width='0.277778em'/>
         <msup><mi>n</mi> <mn>2</mn> </msup></mrow></mtd>
       </mtr>
       <mtr>
        <mtd columnalign='right'><mi>u</mi></mtd>
        <mtd columnalign='left'><mrow><mo>=</mo><mi>v</mi><mo>+</mo><mn>1</mn>
         <mspace width='10.0pt'/><mo>(</mo><mo form='prefix'>mod</mo><mspace width='0.277778em'/></mrow>
         <msup><mi>n</mi> <mn>2</mn> </msup><mo>)</mo></mrow></mtd>
       </mtr>
       <mtr>
        <mtd columnalign='right'><mi>u</mi></mtd>
        <mtd columnalign='left'><mrow><mo>=</mo><mi>v</mi><mo>+</mo><mn>1</mn>
          <mspace width='10.0pt'/><mo>(</mo><msup><mi>n</mi> <mn>2</mn> </msup><mo>)</mo></mrow>
        </mtd>
       </mtr>
      </mtable>
     </math>
    </formula>
:::

Preview ![bmod example](/img/img_121.png). (See also
[here](mml_ex.html#binom)).

body (Tralics environment) {#env-body}
--------------------------

The `body` environment is defined as `\newenvironment{body}{}{}` in
versions up to 2.3 for compatibility reasons. It is now a user-defined
environment for the raweb only. It is undefined otherwise.

\\boolean {#cmd-boolean}
---------

See `` `\newboolean `` \<doc-n.html\#cmd-newboolean\>[\_\_ for how to
create a boolean and ]{.title-ref}`\ifthenelse`
\<doc-i.html\#cmd-ifthenelse\>[\_\_ for how to use it with the
]{.title-ref}[boolean{some-name}]{.title-ref}\` command.

\\bot (math symbol) {#cmd-bot}
-------------------

The `\bot` command is valid only in math mode. It generates a
miscellaneous symbol. It is like `\perp`: `<mo>&bottom;</mo>` (Unicode
U+22A5, ⊥) that renders like ![\$bot\$](/img/img_other_bottom.png). See
description of the `` `\ldots `` \<doc-l.html\#cmd-ldots\>\`\_\_
command.

\\botfigrule {#cmd-botfigrule}
------------

The command `\botfigrule` behaves like `\relax`, in LaTeX it can be
redefined to produce a rule between a float and text that precedes.

\\botmark {#cmd-botmark}
---------

In `\botmark` is the mark text most recently encountered on the page
that was just boxed. Since *Tralics* does not box pages, the expansion
of `\botmark` is always empty.

\\botmarks {#cmd-botmarks}
----------

This is an extension introduced by ε-TeX; an integer is read, expansion
is empty. See `` `\splitbotmark ``
\<doc-s.html\#cmd-splitbotmark\>\`\_\_.

\\bottom (math symbol) {#cmd-bottom}
----------------------

The `\bottom` command is an alias for `\bot`
![\$bottom\$](/img/img_other_bottom.png).

\\bottomfraction {#cmd-bottomfraction}
----------------

Maximum fraction of a page that can be occupied by floats at the bottom.
Unused by *Tralics*. See `` `\intextsep ``
\<doc-i.html\#cmd-intextsep\>\`\_\_.

bottomnumber (counter) {#cmd-bottomnumber}
----------------------

Maximum number of floats at the bottom of a page. Unused by *Tralics*.
See `` `\intextsep `` \<doc-i.html\#cmd-intextsep\>\`\_\_.

\\bowtie (math symbol) {#cmd-bowtie}
----------------------

The `\bowtie` command is valid only in math mode. It generates a
relation symbol: `<mo>&bowtie;</mo>` (Unicode U+22C8,⋈) that renders
like See description of the `` `\le `` \<doc-l.html\#cmd-le\>\`\_\_
command. ![\$bowtie\$](/img/img_t_bowtie.png)

\\Box (math symbol) {#cmd-Cbox}
-------------------

The `\Box` command is valid only in math mode. It generates a square box
`<mo>&25A1;</mo>`. There is the image of `x\Box`
![\$xBox\$](/img/img_119.png).

\\box {#cmd-box}
-----

The `\box` command reads an integer N (a small number between 0 and 255,
see [scanint](doc-s.html#fct-scanint) for details), and returns the
content of the box number N. After that, the box is emptied (the `\copy`
command behaves in the same fashion, but leaves the box unchanged).
Example

::: {.container .ltx-source}
    \setbox12=\xbox{foo}{ok}
    \count3=12
    \copy12 , and \copy 12 , and \box \count3 , and \box 12!
:::

Translation

::: {.container .xml_out}
    <foo>ok</foo>, and <foo>ok</foo>, and <foo>ok</foo>, and !
:::

\\boxast (math symbol) {#cmd-boxast}
----------------------

The `\boxast` command is valid only in math mode. It generates a box
with asterisk `<mo>&#x29C6;</mo>` (Unicode U+29C6, ⧆).

\\boxbox (math symbol) {#cmd-boxbox}
----------------------

The `\boxbox` command is valid only in math mode. It generates a box
with a box `<mo>&29C8;</mo>` (Unicode U+29C8, ⧈).

\\boxbslash (math symbol) {#cmd-boxbslash}
-------------------------

The `\boxbslash` command is valid only in math mode. It generates a box
with a backslash `<mo>&bsolb;</mo>` (Unicode U+29C5, ⧅).

\\boxcircle (math symbol) {#cmd-boxcircle}
-------------------------

The `\boxcircle` command is valid only in math mode. It generates a box
with `<mo>&#x29C7;</mo>` (Unicode U+29C7, ⧇).

\\boxdot (math symbol) {#cmd-boxdot}
----------------------

The `\boxdot` command is valid only in math mode. It generates a box
with a dot `<mo>&dotsquare;</mo>` (Unicode U+22A1, ⊡).

\\boxed {#cmd-boxed}
-------

The `\boxed` command is valid only in math mode. It takes an argument,
and puts a frame around it (like `fbox` in text mode); as the example
below shows, the argument is put in a cell of a table, and the table has
a frame attribute. (See also [here](mml_ex.html#binom)).

::: {.container .xml_out}
    <mtable frame='solid'><mtr><mtd><mi>x</mi></mtd></mtr></mtable>
:::

\\boxempty (math symbol) {#cmd-boxempty}
------------------------

The `\boxempty` command is valid only in math mode. It generates an
empty box. It is an alias for `` `\square ``
\<doc-s.html\#cmd-square\>[\_\_. Translation is
]{.title-ref}[\<mo\>&square;\</mo\>]{.title-ref}\` (Unicode U+25A1, □).

\\boxmaxdepth (rigid length) {#cmd-boxmaxdepth}
----------------------------

You can say `\boxmaxdepth=1.5in`, as a result TeX will make sure that
each vbox on a page has a depth not exceeding 1.5in (by shifting it up
if necessary). Ignored by *Tralics*. (See
[scandimen](doc-s.html#fct-scandimen) for details of argument scanning).

\\boxminus (math symbol) {#cmd-boxminus}
------------------------

The `\boxminus` command is valid only in math mode. It generates a box
with a minus sign `<mo>&boxminus;</mo>` (Unicode U+229F, ⊟).

\\boxplus (math symbol) {#cmd-boxplus}
-----------------------

The `\boxplus` command is valid only in math mode. It generates a box
with a plus sign `<mo>&boxplus;</mo>` (Unicode U+229E, ⊞).

boxslash\\ (math symbol) {#cmd-boxslash}
------------------------

The `\boxslash` command is valid only in math mode. It generates a box
with slash `<mo>&solb;</mo>` (Unicode U+29C4, ⧄).

\\boxtimes (math symbol) {#cmd-boxtimes}
------------------------

The `\boxtimes` command is valid only in math mode. It generates a box
with product sign `<mo>&boxtimes;</mo>` (Unicode U+22A0, ⊠).

\\bpers (Tralics command) {#cmd-bpers}
-------------------------

This command is used for an author or editor in a bibliography. It takes
one optional and four required arguments (first name, initials,
particle, last name, junior name). For an example, see `` `\citation ``
\<doc-c.html\#cmd-citation\>[\_\_. Here the arguments of the command are
]{.title-ref}[bpers\[David\]{D.}{}{Carlisle}{}]{.title-ref}[, from the
database value \'David Carlisle\'. The translation is a
]{.title-ref}[\<bpers\>]{.title-ref}[ element, with five attributes (in
the case of particle and junior, no attribute is created if the field is
empty, so that the effective number of attributes is between three and
five). An example is ]{.title-ref}[\<bpers prenom=\'D.\'
nom=\'Carlisle\' prenomcomplet=\'David\'/\>]{.title-ref}\`.

\\bprime (math symbol) {#cmd-bprime}
----------------------

The `\bprime` command is valid only in math mode. It generates
`<mo>&bprime;</mo>` (Unicode U+2035).

\\brace, \\brack (math construction) {#cmd-brace}
------------------------------------

Instead of `{a\brace b}` or `{a\brack b}` you should use
`\genfrac\{\}{0pt}{}{a}{b}` and `\genfrac[]{0pt}{}{a}{b}`.

\\bracevert (math symbol) {#cmd-bracevert}
-------------------------

The `\bracevert` command is valid only in math mode. It is an alias for
`` `\vert `` \<doc-v.html\#cmd-vert\>\`\_\_.

\\break {#cmd-break}
-------

The `\break` command is ignored. It is `\penalty-10000` in LaTeX.

\\breve {#cmd-breve}
-------

The `\breve` command puts a breve accent over a kernel. It works only in
math mode. See also the `` `\acute `` \<doc-a.html\#cmd-acute\>\`\_\_
command.

\\brokenpenalty (internal integer) {#cmd-brokenpenalty}
----------------------------------

When you say `\brokenpenalty=98`, then TeX will use 98 as penalty for a
page break at a discretionary break (case where a word is broken, the
two parts being on two different pages). Unused by *Tralics*. (See
[scanint](doc-s.html#fct-scanint) for details of argument scanning).

\\Bumpeq (math character) {#cmd-Bumpeq}
-------------------------

The `\Bumpeq` command is valid only in math mode. It generates
`<mo>&Bumpeq;</mo>` (Unicode U+224E, ≎).

\\bullet (math character) {#cmd-bullet}
-------------------------

The `\bullet` command is valid only in math mode. It generates a binary
operator: `<mo>&bullet;</mo>` (Unicde U+2022, •) See description of the
`` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\bye {#cmd-bye}
-----

This is defined in PlainTeX as : `\par \vfill \supereject \end`. In
*Tralics*, we make it equivalent to `\endinput`.
