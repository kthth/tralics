All commands, alphabetic order; letter O
========================================

This page contains the description of [\\o](#cmd-o), [\\O](#cmd-co),
[\\oast](#cmd-oast), [\\obar](#cmd-obar), [\\obeylines](#cmd-obeylines),
[\\obeyspaces](#cmd-obeyspaces), [\\oblong](#cmd-oblong),
[\\ocircle](#cmd-ocircle), [\\oddsidemargin](#cmd-oddsidemargin),
[\\odot](#cmd-odot), [\\oe](#cmd-oe), [\\OE](#cmd-coe), [\\of](#cmd-of),
[\\offinterlineskip](#cmd-offinterlineskip), [\\og](#cmd-og),
[\\ogreaterthan](#cmd-ogreaterthan), [\\oint](#cmd-oint),
[\\oldstylenums](#cmd-oldstylenums), [\\olessthan](#cmd-olessthan),
[\\omega](#cmd-omega), [\\Omega](#cmd-comega), [\\ominus](#cmd-ominus),
[\\omit](#cmd-omit), [\\omitcite](#cmd-omitcite), [\\\@ne](#cmd-one),
[\\on\@line](#cmd-online), [\\onecolumn](#cmd-onecolumn),
[\\\@onlypreamble](#cmd-onlypreamble), [\\openin](#cmd-openin),
[\\openout](#cmd-openout), [\\operatorname](#cmd-operatorname),
[\\operatornamewithlimits](#cmd-operatornamewithlimits),
[\\oplus](#cmd-oplus), [\\OptionNotUsed](#cmd-optionnotused),
[\\or](#cmd-or), [\\OR](#cmd-cor), [\\oslash](#cmd-oslash),
[\\otimes](#cmd-otimes), [\\outer](#cmd-outer), [\\output](#cmd-output),
[\\outputpenalty](#cmd-outputpenalty), [\\oval](#cmd-oval),
[\\over](#cmd-over), [\\overbrace](#cmd-overbrace),
[\\overfullrule](#cmd-overfullrule),
[\\overleftarrow](#cmd-overleftarrow),
[\\overleftrightarrow](#cmd-overleftrightarrow),
[\\overline](#cmd-overline), [\\overrightarrow](#cmd-overrightarrow),
[\\overset](#cmd-overset), [\\overwithdelims](#cmd-overwithdelims),
[\\owns](#cmd-owns).

------------------------------------------------------------------------

\\o (constant) {#cmd-o}
--------------

The `\o` command translates to a letter o with stroke, ø or `&#xF8;`.
See description of the [latin supplement
characters](doc-chars.html#latin).

\\O (constant) {#cmd-co}
--------------

The `\O` command translates to a capital letter o with stroke, Ø or
`&#xD8;`. See description of the [latin supplement
characters](doc-chars.html#latin).

\\oast (math symbol) {#cmd-oast}
--------------------

The `\oast` command is an alias for `` `\circledast ``
\<doc-c.html\#cmd-circledast\>\`\_\_ (Unicode U+229B; ⊛).

\\obar (constant) {#cmd-obar}
-----------------

The `\obar` command is valid only in math mode. It generates
`<mo>&omid;</mo>` (Unicode U+29B6, ⦶).

\\obeylines {#cmd-obeylines}
-----------

This commands makes the end-of-line character (control-M) active and
behave like `\par`.

\\obeyspaces {#cmd-obeyspaces}
------------

This commands makes the space character active.

\\oblong (math symbol) {#cmd-oblong}
----------------------

The `\oblong` command is an alias for `` `\square ``
\<doc-s.html\#cmd-square\>\`\_\_ (Unicode U+25A1, □).

\\ocircle (math symbol) {#cmd-ocircle}
-----------------------

The `\ocircle` command is an alias for `` `\circledcirc ``
\<doc-c.html\#cmd-circledcirc\>\`\_\_ (Unicode U+229A, ⊚) (a circle in a
circle).

\\oddsidemargin (rigid length) {#cmd-oddsidemargin}
------------------------------

This is a dimension, defined by LaTeX, but unused by *Tralics*.

\\odot (math symbol) {#cmd-odot}
--------------------

The `\odot` command is valid only in math mode. It generates a binary
operator: `<mo>&odot;</mo>` (Unicode U+2299, ⊙). See description of the
`` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\oe (constant) {#cmd-oe}
---------------

The `\oe` command translates to an oe ligature (character U+153, œ). See
description of the [extended latin
characters](doc-chars.html#ext-latin).

\\OE (constant) {#cmd-coe}
---------------

The `\OE` command translates to an uppercase oe ligature (Unicode U+152,
Œ) See description of the [extended latin
characters](doc-chars.html#ext-latin).

\\of {#cmd-of}
----

The `\of` command is undefined. However you say `\root 3 \of 4` if you
do not like the LaTeX syntax `\sqrt[3]{4}`.

\\offinterlineskip {#cmd-offinterlineskip}
------------------

The `\offinterlineskip` command is ignored. In LaTeX, it sets
`\prevdepth` to a magic value that inhibits insertion of interline glue,
it sets `\lineskip` to zero and `\lineskiplimit` to the maximum possible
value.

\\og (constant) {#cmd-og}
---------------

The `\og` command stands for "ouvrez-les-guillemets". It is more or less
the same as `«`. Translation is `&#xAB;&#xA0;`. For more info see the
[latin supplement characters](doc-chars.html#latin).

\\ogreaterthan (math symbol) {#cmd-ogreaterthan}
----------------------------

The `\ogreaterthan` command is valid only in math mode. Its translation
is `<mo>&ogt;</mo>` (Unicode U+29C1, ⧁).

\\oint (constant) {#cmd-oint}
-----------------

The `\oint` command is valid only in math mode. Its translation is a
variable-sized symbol: `<mo>&oint;</mo>` (Unicode U+222E, ∮). For an
example see the `` `\sum `` \<doc-s.html\#cmd-sum\>\`\_\_ command.

\\oldstylenums {#cmd-oldstylenums}
--------------

The `\oldstylenums` command takes an argument and puts it in a `<hi>`
element.

::: {.container .ltx-source}
    \begin{center}
    1234567890 \\
    \oldstylenums{1234567890}
    \end{center}
:::

::: {.container .xml_out}
    <p rend='center'>1234567890 </p>
    <p rend='center'><hi rend='oldstyle'>1234567890</hi></p>
:::

The preview might be the following. This is not perfect:
![oldstylenums{\...}](/img/img_38.png).

\\olessthan (math symbol) {#cmd-olessthan}
-------------------------

The `\olessthan` command is valid only in math mode. Its translation is
`<mo>&olt;</mo>` (Unicode U+29C0, ⧀).

\\omega (math symbol) {#cmd-omega}
---------------------

The `\omega` command is valid only in math mode. It generates a Greek
letter: `<mi>&omega;</mi>` (Unicode U+3C9, ω). See description of the
`` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\Omega (math symbol) {#cmd-comega}
---------------------

The `\Omega` command is valid only in math mode. It generates an
uppercase Greek letter: `<mi>&Omega;</mi>` (Unicode U+3A9, Ω). See
description of the `` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_
command.

\\ominus (constant) {#cmd-ominus}
-------------------

The `\ominus` command is valid only in math mode. It generates a binary
operator: `<mo>&ominus;</mo>` (Unicode U+2296, ⊖). See description of
the `` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\omit {#cmd-omit}
------

The `\omit` command has as effect to omit the template of a cell in a
table. This command is a primitive for `\halign`. For the `tabular`
environment, you should use `\multicolumn{1}{xx}{yy}` instead, where xx
is the desired template and yy the text.

Since `\halign` is not implemented, the `\omit` command provokes an
error in the current version of *Tralics*.

\\omitcite \[Tralics command\] {#cmd-omitcite}
------------------------------

The effect of `\omitcite{something}` is to omit the reference given as
arguemnt from the bibliography. It is useful in the case of
`\nocite{*}`. For further details, see the omitcite.tex file is the
Tralics sources.

\\\@ne {#cmd-one}
------

This command is made equal to the integer one, via `\chardef` (use it
only in contexts where an integer is expected). For an example, see
`` `\m@ne `` \<<doc-m.html#cmd-m@ne>\>\`\_\_.

\\onecolumn {#cmd-onecolumn}
-----------

This command is currently ignored.

\\<on@line> {#cmd-online}
-----------

The `\on@line`command can be used when signaling error; its expansion
could be `on input line 17`.

\\\@onlypreamble {#cmd-onlypreamble}
----------------

If you say `\@onlypreamle{\foo}`, then the `\begin{document}` modifies
the definition of `\foo`, provoking an error: *Can be used only in
preamble*.

\\openin {#cmd-openin}
--------

| You can say `\openin 5=name`, where the number 5 could be replaced by
  any number between 0 and 15, the equals sign is optional, and the file
  name is scanned like `\input` (the TeX primitive).
| ![See\...](/img/AR.png) (see [scanint](doc-s.html#fct-scanint) for
  details of argument scanning) (See also `` `\input ``
  \<doc-i.html\#cmd-input\>\`\_\_).

If a file is associated to the channel, it will be closed (in the same
fashion as by `\closein`). Nothing special happens if the file cannot be
opened. Otherwise, you can use `\read` to read from the the file
associated to the channel.

Let\'s assume that the file tortureaux.tex contains the following six
lines (the second and the last lines are blank).

::: {.container .ltx-source}
    abc

    \a \b {\c
    {} \d} \e
    123
:::

The following code assume that `\testeq XY` will signal an error if
arguments are not equal. Note that the second `\read` reads the empty
line; it is really empty because `\endlinechar` is not an integer
between 0 and 2^16^-1. The `\read` that follows will read two lines,
because braces have to match.

::: {.container .ltx-source}
    {
    \openin 5=tortureaux
    \endlinechar=-1
    \ifeof5 \badifeofatentry\fi
    \read 5 to \foo\testeq\foo{abc}
    \read 5 to \foo\testeq\foo{}
    \read 5 to \foo\testeq\foo{\a\b{\c{} \d} \e}
    \global\read 5 to \foo
    \closein5\relax
    \ifeof5\else\badifeofatexit\fi
    }\testeq\foo{123}
    \ifeof3\else \badifeofnonexists\fi
:::

\\openout {#cmd-openout}
---------

You can say `\openout 5=name`, where the number 5 could be replaced by
any number between 0 and 15 (see [scanint](doc-s.html#fct-scanint) for
details). This closes any file attached to the output channel 5. It
opens the file `name` for output (if the file exists, it content will be
lost). In case of success, it marks the output channel as open
(otherwise, it is closed).

The channel can be closed by `\closeout`, and you can write on it via
`\write`. These three commands are whatsits: objects that are not
immediately evaluated, but only when the box in which they are contained
is shipped out, unless they are preceded by `\immediate`, case where the
action is immediate. In *Tralics*, the `\shipout` command is never
called, so that these actions are always immediate.

One reason why `\immediate` is needed is so that `\write5{\thepage}`
prints the right page number.

You can say `\typeout{foo}`, this is the same as `\write 17{foo}`.

If you say `\write N{list}`, all tokens in the list are expanded, and
the token list is printed. In case N refers to a valid output channel
(associated to a file), printing goes to the file associated to this
channel. Otherwise, output goes to the user\'s transcript file and to
the terminal. Output is restricted to the transcript file if N is
negative.

In the case where N=18, and *Tralics* is called with the \--shell-escape
option, then output goes to a shell, and is executed as an external Unix
program (this depends on the operating system).

\\operatorname {#cmd-operatorname}
--------------

This command can be used in math mode only, and `\operatorname{sin}` has
the same meaning as `\sin`. There are some restrictions on the
arguments: only characters are allowed. Since the LaTeX companion cites
an example of the form `\operatorname{ess\,sup}`, commands that produce
a space are accepted; spaces are otherwise ignored. When you say
`\DeclareMathOperator{\Sin}{sin}`, this defines a command whose meaning
is `\operatorname{sin}`. These two commands accept a starred form, see
example

::: {.container .ltx-source}
    \DeclareMathOperator{\Sin}{sin}
    \DeclareMathOperator*{\Limsup}{lim \, sup}
    $\Sin = \sin = \operatorname{sin} $
    $\Limsup = \limsup = \operatorname*{lim\;sup} $
:::

Translation

::: {.container .xml_out}
    <formula type='inline'>
      <math xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow>
          <mo form='prefix'>sin</mo>
          <mo>=</mo>
          <mo form='prefix'>sin</mo>
          <mo>=</mo>
          <mo form='prefix'>sin</mo>
        </mrow>
      </math>
    </formula>
    <formula type='inline'>
      <math xmlns='http://www.w3.org/1998/Math/MathML'>
        <mrow>
          <mo movablelimits='true' form='prefix'>lim sup</mo>
          <mo>=</mo>
          <mo movablelimits='true' form='prefix'>lim sup</mo>
          <mo>=</mo>
          <mo movablelimits='true' form='prefix'>lim sup</mo>
        </mrow>
      </math>
    </formula>
:::

\\operatornamewithlimits {#cmd-operatornamewithlimits}
------------------------

This is the same as `\operatorname*`, see above.

\\OptionNotUsed {#cmd-optionnotused}
---------------

This is the default handler for package and class options. In the case
of a package, the option is ignored, in the case of a class the option
is added to the list of global options. You can redefine the command if
the default behavior is not adequate.

\\oplus (math symbol) {#cmd-oplus}
---------------------

The `\oplus` command is valid only in math mode. It generates a binary
operator: `<mo>&oplus;</mo>` (Unicode U+2295, ⊕). See description of the
`` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\or {#cmd-or}
----

The command `\or` is usually used to separate clauses inside an
`\ifcase` construct. It can be used as boolean connector inside
conditionals defined by `` `\ifthenelse ``
\<doc-i.html\#cmd-ifthenelse\>[\_\_. (See ]{.title-ref}\\if\...
\<doc-i.html\#cmd-ifxxx\>\`\_\_ for details).

\\OR {#cmd-cor}
----

It can be used as boolean connector (equivalent to `\or`) inside
conditionals defined by `` `\ifthenelse ``
\<doc-i.html\#cmd-ifthenelse\>\`\_\_.

\\oslash (math symbol) {#cmd-oslash}
----------------------

The `\oslash` command is valid only in math mode. It generates a binary
operator: `<mo>&oslash;</mo>` (Unicode U+2298, ⊘). See description of
the `` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\otimes (math symbol) {#cmd-otimes}
----------------------

The `\otimes` command is valid only in math mode. It generates a binary
operator: `<mo>&otimes;</mo>` (Unicode U+2297, ⊗). See description of
the `` `\pm `` \<doc-p.html\#cmd-pm\>\`\_\_ command.

\\outer {#cmd-outer}
-------

| You can say `\outer\def\foo....`. This defines the `\foo` command to
  be `\outer`, and this makes `\foo` behave like an end-of-file in many
  situations, for instance used as as argument of `\xx`, it will signal
  an error of the form *Runaway argument? Forbidden control sequence
  \\foo found while scanning use of \\xx.* A test done by `\ifx` is
  false if one command is `\outer` and the other is not.
| ![See\...](/img/AR.png) See also the `` `\long ``
  \<doc-l.html\#cmd-long\>\`\_\_ command.

\\output {#cmd-output}
--------

The result of `\output={\foo}\the\output\the\output` is the same
`\foo\foo`. It is however unwise in TeX to use `\output` like this; in
fact, whenever a page is full, TeX puts it in `\box255` and evaluates
the tokens of `\output`. After that, the box should be empty. On the
other hand `\deadcycles` is increased (it is set to zero by `\shipout`).
Since *Tralics* does not create pages of text, the output routine is
never called, and `\deadcycles` is not modified.

\\outputpenalty (internal integer) {#cmd-outputpenalty}
----------------------------------

| You can modify the `\outputpenalty` integer variable; however, TeX
  does not use it, it modifies it: it holds the value of the penalty
  that was at a page break (or 10000 otherwise). Unused by *Tralics*.
  Used a lot by LaTeX.
| ![See\...](/img/AR.png) (See [scanint](doc-s.html#fct-scanint) for
  details of argument scanning).

\\oval {#cmd-oval}
------

You say `\oval(dx,dy)[part]` in order to put oval into a picture. See
description of the `` `picture `` \<doc-p.html\#env-picture\>[\_\_
environment for the syntax of the ]{.title-ref}[(dx,dy)]{.title-ref}[
part, and some examples. In general, the
]{.title-ref}[oval]{.title-ref}[ is the argument of a
]{.title-ref}[put(x,y){}]{.title-ref}[ command, and the
]{.title-ref}[(x,y)]{.title-ref}[ positions indicate the center of a
rectangle, of size ]{.title-ref}[dx]{.title-ref}[ by
]{.title-ref}[dy]{.title-ref}[, in which the oval should be drawn. If
]{.title-ref}[\[part\]]{.title-ref}\` is given, only part of the oval is
drawn: the part can be t, b, l, r (top, bottom, left, right), or two
such letters (tl means top left).

\\over {#cmd-over}
------

The `\over` command is a TeX primitive that should not be used in LaTeX.
It is better to use `\frac` instead. We give here an example of `\over`
and its variants. A construction like `a \over b \over c` is illegal in
TeX. It generates an error in *Tralics*. In the case of
`{a \choose b} \quad {a\over b} \above1pt{c\over d}` the numerator
contains the `\choose` and the `\over`. This was not the intent of the
author of the code. This is one reason why `\over` commands and such are
discouraged. Example:

::: {.container .ltx-source}
    ${a\over b}\quad {a\above1pt b}\quad {a\atop b}$
    ${a\overwithdelims() b}\quad {a\abovewithdelims()1pt b}%
      \quad {a\atopwithdelims() b}$
:::

::: {.container .xml_out}
    <formula type='inline'><math xmlns='http://www.w3.org/1998/Math/MathML'><mrow>
      <mfrac><mi>a</mi> <mi>b</mi></mfrac>
      <mspace width='1.em'/>
      <mfrac linethickness='1pt'><mi>a</mi> <mi>b</mi></mfrac>
      <mspace width='1.em'/>
      <mfrac linethickness='0.0pt'><mi>a</mi> <mi>b</mi></mfrac>
    </mrow></math></formula>
    <formula type='inline'><math xmlns='http://www.w3.org/1998/Math/MathML'><mrow>
      <mfenced open='(' close=')'><mfrac><mi>a</mi> <mi>b</mi></mfrac></mfenced>
      <mspace width='1.em'/>
      <mfenced open='(' close=')'><mfrac linethickness='1pt'><mi>a</mi> <mi>b</mi></mfrac></mfenced>
      <mspace width='1.em'/>
      <mfenced open='(' close=')'><mfrac linethickness='0.0pt'><mi>a</mi> <mi>b</mi></mfrac></mfenced>
    </mrow></math></formula>
:::

Preview ![over etc](/img/img_59.png) (see also
[here](mml_ex.html#binom))

\\overbrace {#cmd-overbrace}
-----------

| The `\overbrace` command puts an horizontal brace over a kernel. It
  works only in math mode. Example: ![overbrace
  ex.](/img/img_t_overbrace.png).
| ![See\...](/img/AR.png) See also the `` `\acute ``
  \<doc-a.html\#cmd-acute\>\`\_\_ command.

\\overfullrule (rigid length) {#cmd-overfullrule}
-----------------------------

| You can say `\overfullrule=5pt`, as a result TeX will insert a rule of
  width 5pt at the end of each overfull rule. This is set to 0pt by
  LaTeX, ignored by *Tralics*.
| ![See\...](/img/AR.png) (See [scandimen](doc-s.html#fct-scandimen) for
  details of argument scanning).

\\overleftarrow {#cmd-overleftarrow}
---------------

| The `\overleftarrow` command puts an arrow accent (Unicode character
  U+2190, ←) (pointing to the left) over a kernel. Example:
  ![overleftarrow ex.](/img/img_t_overleftarrow.png). It works only in
  math mode.
| ![See\...](/img/AR.png) See also the `` `\acute ``
  \<doc-a.html\#cmd-acute\>\`\_\_ command.

\\overleftrightarrow {#cmd-overleftrightarrow}
--------------------

The `\overleftrightarrow` command puts an arrow accent (pointing to the
left and right) over a kernel. (Unicode character U+2194, ↔) It works
only in math mode.

\\overline {#cmd-overline}
----------

The `\overline` command puts a line over a kernel. It works only in math
mode. See also the `` `\acute `` \<doc-a.html\#cmd-acute\>\`\_\_
command.

\\overrightarrow {#cmd-overrightarrow}
----------------

The `\overrightarrow` command puts an arrow accent (Unicode character
U+2192, →) (pointing to the right) over a kernel. Example:
![overrightarrow](/img/img_t_overrightarrow.png). It works only in math
mode. See also the `` `\acute `` \<doc-a.html\#cmd-acute\>\`\_\_
command.

\\overset {#cmd-overset}
---------

The `\overset` command takes two arguments A and B, it places A
(superscript size) over B. It works only in math mode. See also the
`` `\acute `` \<doc-a.html\#cmd-acute\>\`\_\_ command.

\\overwithdelims {#cmd-overwithdelims}
----------------

| The `\overwithdelims` command is a TeX primitive that should not be
  used. Instead of `aa \overwithdelims()bb` you should use
  `\genfrac(){}{}{aa}{bb}`.
| ![See\...](/img/AR.png) See `` `\genfrac ``
  \<doc-g.html\#cmd-genfrac\>[\_\_ and ]{.title-ref}`\over`
  \<doc-o.html\#cmd-over\>\`\_\_.

\\owns (math symbol) {#cmd-owns}
--------------------

The `\owns` command is equivalent to `\ni`. It gives a normal symbol
`<mo>&ni;</mo>` (Unicode U+220B, ∋). See also description of the
`` `\smallint `` \<doc-s.html\#cmd-smallint\>\`\_\_ command.
