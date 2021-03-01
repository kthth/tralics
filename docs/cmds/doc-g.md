All commands, alphabetic order; letter G
========================================

| This page contains the description of the following commands
  [\\g\@addto\@macro](#cmd-g-addto-macro), [\\Game](#cmd-Game),
  [\\gamma](#cmd-gamma), [\\Gamma](#cmd-cgamma), [\\gcd](#cmd-gcd),
  [\\gdef](#cmd-gdef), [\\gdelpresetkeys](#cmd-gpresetkeys),
  [\\gdelsavekeys](#cmd-gsavekeys), [\\ge](#cmd-ge),
  [\\genfrac](#cmd-genfrac), [\\geq](#cmd-ge), [\\geqq](#cmd-geqq),
  [\\geqslant](#cmd-geqslant), [\\gets](#cmd-gets), [\\gg](#cmd-gg),
  [\\ggg](#cmd-ggg), [\\gggtr](#cmd-gggtr), [\\gimel](#cmd-gimel),
  [\\glo](#cmd-glo), [\\global](#cmd-global),
  [\\globaldefs](#cmd-globaldefs), [\\glossary](doc-i.html#cmd-index),
  [\\glueexpr](#cmd-glueexpr), [\\glueshrink](#cmd-glueshrink),
  [\\glueshrinkorder](#cmd-glueshrinkorder),
  [\\gluestretch](#cmd-gluestretch),
  [\\gluestretchorder](#cmd-gluestretchorder),
  [\\gluetomu](#cmd-gluetomu), [\\gnapprox](#cmd-gnapprox),
  [\\gneq](#cmd-gneq), [\\gneqq](#cmd-gneqq), [\\gnsim](#cmd-gnsim),
  [\\\@gobble](#cmd-gobble), [\\\@gobblefour](#cmd-gobble),
  [\\\@gobbletwo](#cmd-gobble), [\\goodbreak](#cmd-goodbreak),
  [\\gpresetkeys](#cmd-gpresetkeys), [\\grabenv](#cmd-grabenv),
  [\\grave](#cmd-grave), [\\gsavekeys](#cmd-gsavekeys),
  [\\gtrapprox](#cmd-gtrapprox), [\\gtrdot](#cmd-gtrdot),
  [\\gtreqless](#cmd-gtreqless), [\\gtreqqless](#cmd-gtreqqless),
  [\\gtrless](#cmd-gtrless), [\\gtrsim](#cmd-gtrsim),
  [\\guillemotleft](#cmd-guillemotleft),
  [\\guillemotright](#cmd-guillemotright),
  [\\gunpresetkeys](#cmd-gpresetkeys), [\\gunsavekeys](#cmd-gsavekeys),
| and environments [gather](#env-gather), [glossaire](#env-glossaire),
  [guillemets](#cmd-guillemets).

------------------------------------------------------------------------

\\<g@addto@macro> {#cmd-g-addto-macro}
-----------------

If you say `\g@addt@macro\foo{bar}`, this will have as effect to
globally change the macro `\foo`, by appending to its right the tokens
`bar`. This is similar to `\addto@hook`, but is more widely used because
there is only a small number of token list registers. See also
[\\\@cons](doc-c.html#cmd-car).

\\Game (math symbol) {#cmd-Game}
--------------------

The `\Game` command is valid only in math mode. It generates
`<mi>&#x2141;</mi>` (Unicode U+2141, ⅁).

\\gamma (math symbol) {#cmd-gamma}
---------------------

The `\gamma` command is valid only in math mode. It generates a Greek
letter: `<mi>&gamma;</mi>` (Unicode U+3B3, γ). See description of the
`` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_ command.

\\Gamma (math symbol) {#cmd-cgamma}
---------------------

The `\Gamma` command is valid only in math mode. It generates an
uppercase Greek letter: `<mi>&Gamma;</mi>` (Unicode U+393, Γ). See
description of the `` `\alpha `` \<doc-a.html\#cmd-alpha\>\`\_\_
command.

gather (environment) {#env-gather}
--------------------

This environment has to be used outside math mode, it contains equations
separated by `\\` commands. If the counter
[\\multi\@math\@label](doc-m.html#cmd-multimathlabel) is non-zero, or if
*Tralics* is called with option -multi_math_label then an anchor is
added to every row, its `id-text` is obtained by incrementing the
equation counter. In the example shown, the anchor is attached to the
formula and no counter is incremented. (See also
[here](mml_ex.html#gather))

::: {.container .ltx-source}
    \begin{gather}1<2\\3<4\end{gather}
:::

Translation

::: {.container .xml_out}
    <formula id-text='mid1' id='uid1' type='display'>
     <math mode='display' xmlns='http://www.w3.org/1998/Math/MathML'>
      <mtable displaystyle='true'>
       <mtr><mtd><mrow><mn>1</mn><mo>&lt;</mo><mn>2</mn></mrow></mtd></mtr>
       <mtr><mtd><mrow><mn>3</mn><mo>&lt;</mo><mn>4</mn></mrow></mtd></mtr>
      </mtable>
     </math>
    </formula>
:::

\\gcd (math symbol) {#cmd-gcd}
-------------------

The `\gcd` command is valid only in math mode. Its translation is a math
operator of the same name:
`<mo form='prefix' movablelimits='true'>gcd</mo>`. For an example see
the `` `\log `` \<doc-l.html\#cmd-log\>\`\_\_ command.

\\gdef {#cmd-gdef}
------

You can say `\gdef\foo{bar}`. The syntax is the same as `` `\def ``
\<doc-d.html\#cmd-def\>\`\_\_, but the definition is global.

You can put the prefix `\global` before `\gdef`, but this is useless.

\\ge, \\geq (math symbol) {#cmd-ge}
-------------------------

The `\ge` command (and is variant `\geq`) is valid only in math mode. It
generates a relation symbol: `<mo>&ge;</mo>` (Unicode U+2265, ≥). See
description of the `` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\genfrac {#cmd-genfrac}
---------

The `\genfrac` command is valid only in math mode. It takes six
arguments, say L, R, w, s, N, D. The translation is a fraction N over D,
with left and right delimiters L and R. The parameter w specifies the
width of the fraction rule. It can be omitted. The parameter s specifies
the style, it is a number between 0 and 3, interpreted as
`\displaystyle`, `\textstyle`, `scriptstyle`, `\scriptscriptstyle`. It
can be empty.

::: {.container .ltx-source}
    $$\genfrac{}{}{}{}12 % this is \frac 
    \genfrac[]{2pt}{2}{aaa}{bbb} % brackets, small, thick 
    \genfrac(){0cm}{0}nm % this is \dbinom 
    $$
:::

::: {.container .xml_out}
    <formula type='display'>
     <math mode='display' xmlns='http://www.w3.org/1998/Math/MathML'>
      <mrow>
       <!-- \genfrac{}{}{}{}12 -->
       <mfrac><mn>1</mn> <mn>2</mn></mfrac>
       <!-- \genfrac[]{2pt}{2}{aaa}{bbb} -->
       <mfenced open='[' close=']'>
        <mstyle scriptlevel='1' displaystyle='false'>
         <mfrac linethickness='2.0pt'>
          <mrow><mi>a</mi><mi>a</mi><mi>a</mi></mrow> 
          <mrow><mi>b</mi><mi>b</mi><mi>b</mi></mrow>
         </mfrac>
        </mstyle>
       </mfenced>
       <!--\genfrac(){0cm}{0}nm -->
       <mfenced open='(' close=')'>
        <mstyle scriptlevel='0' displaystyle='true'>
         <mfrac linethickness='0.0pt'><mi>n</mi> <mi>m</mi></mfrac>
        </mstyle>
       </mfenced>
      </mrow>
     </math>
    </formula>
:::

Preview ![genfrac](/img/img_58.png)

\\geqq (math symbol) {#cmd-geqq}
--------------------

The `\geqq` command is valid only in math mode; it is a variant of the
greater-or-equal symbol: `<mo>&geqq;</mo>` (Unicode U+2267, ≧).

\\geqslant (math symbol) {#cmd-geqslant}
------------------------

The `\geqslant` command is valid only in math mode; it is a variant of
the greater-or-equal symbol: `<mo>&geqslant;</mo>` (Unicode U+2A7E, ⩾).
See also description of the `` `\smallint ``
\<doc-s.html\#cmd-smallint\>\`\_\_ command.

\\gets (math symbol) {#cmd-gets}
--------------------

The `\gets` command is equivalent to the `\leftarrow` command:
`<mo>&leftarrow;</mo>` (Unicode U+2190, ←). See also description of the
`` `\smallint `` \<doc-s.html\#cmd-smallint\>\`\_\_ command.

\\gg (math symbol) {#cmd-gg}
------------------

The `\gg` command is valid only in math mode. It generates a relation
symbol: `<mo>&gg;</mo>` (Unicode U+226B, ≫). See description of the
`` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\ggg (math symbol) {#cmd-ggg}
-------------------

The `\ggg` command is valid only in math mode. It generates a relation
symbol: `<mo>&ggg;</mo>` (Unicode U+22D9, ⋙).

\\gggtr (math symbol) {#cmd-gggtr}
---------------------

The `\gggtr` command is valid only in math mode. It generates a relation
symbol: `<mo>&ggg;</mo>` (Unicode U+22D9, ⋙).

\\gimel (math symbol) {#cmd-gimel}
---------------------

The `\gimel` command is valid only in math mode. It generates
`<mi>&gimel;</mi>` (Unicode U+2137, ℷ).

\\global {#cmd-global}
--------

If you say `\global\def...` then the definition will be global, unless
`\globaldefs` is negative. The prefix can be used before any assignment,
like `\let`, or `\catcode25=` `\advance\count0`. Note that `\global\def`
is the same as `\gdef` and `\global\edef` is the same as `\xdef`.

\\globaldefs {#cmd-globaldefs}
------------

When you say `\globaldefs=75` (or any positive value), then all
following assignments are global. If `\globaldefs` is negative, then all
following assignments are local, even those prefixed with `\global`. If
the value is zero, only those prefixed with `\global` are global. (See
[scanint](doc-s.html#fct-scanint) for details of argument scanning).

Example. The following code translates to 023400. Note that the second
assignment to `\globaldefs` is global, so that this variable is negative
outside the group.

::: {.container .ltx-source}
    \count0=0 \count1=0 \count10=0 \count11=0 \count20=0  \count21=0 
    {
      \count0=1 \global\count1=2
      \globaldefs=1
      \count10=3 \global\count11=4
      \globaldefs=-1
      \count20=5 \global\count21=6
    }
    \the\count0 \the\count1 \the\count10 \the\count11 \the\count20 \the\count21 
    \globaldefs=0
:::

\\glo (Raweb command) {#cmd-glo}
---------------------

The `\glo` command takes two arguments. The translation of `\glo{a}{b}`
is the same as `\item[a]{b}`, namely
`<label>a</label><item> <p>b</p></item>`

glossaire (Raweb environment) {#env-glossaire}
-----------------------------

This is an environment in which you can put `\glo` commands. (do not
confuse with the [\\glossary](doc-i.html#cmd-index) command). Example.

::: {.container .ltx-source}
    \begin{glossaire} \glo{x1}{y1}\glo{x2}{y2}\end{glossaire}
:::

The translation will be:

::: {.container .xml_out}
    <list type='gloss'>
     <head>Glossary</head>
     <label>x1</label>
     <item><p>y1</p></item>
     <label>x2</label>
     <item><p>y2</p></item>
    </list>
:::

Note that names are not hard-coded. If the configuration file contains
the following

::: {.container .ltx-source}
    att_gloss_type = "Gloss"
    xml_gloitem_name = "Glolabel"
    xml_item_name = "Item"
    xml_labelitem_name = "Label"
    xml_list_name = "List"
    xml_head_name = "Head"
    xml_glo_name = "The famous glossary"
:::

then the translation will be:

::: {.container .xml_out}
    <List type='Gloss'>
     <Head>The famous glossary</Head>
     <Glolabel>x1</Glolabel>
     <Item><p>y1</p></Item>
     <Glolabel>x2</Glolabel>
     <Item><p>y2</p></Item>
    </List>
:::

\\glueexpr (e-TeX extension) {#cmd-glueexpr}
----------------------------

Like `` `\numexpr `` \<doc-n.html\#cmd-numexpr\>\`\_\_, but scans glue.

\\glueshrink (e-TeX extension) {#cmd-glueshrink}
------------------------------

\\glueshrinkorder (e-TeX extension) {#cmd-glueshrinkorder}
-----------------------------------

\\gluestretch (e-TeX extension) {#cmd-gluestretch}
-------------------------------

\\gluestretchorder (e-TeX extension) {#cmd-gluestretchorder}
------------------------------------

The commands `\gluestretchorder`, `\glueshrinkorder`, `\gluestretch`,
`\glueshrink` can be used when some internal quantity is scanned, for
instance after `\the`. They read some glue and return one part of the
glue, it can be the stretch order or the shrink order (an integer
between 0 and 3), or the stretch or shrink value (as a dimension). In
the case of `3pt plus 4pt minus 5pt`, the stretch value is 4pt, the
shrink value is 5pt, the strech and shrink orders are zero. The value
3pt can be obtained by converting the glue to a dimension. In the case
of `3pt plus 4fil minus 5fill`, the values are the same the stretch
order is one, the shrink order is 2. Order 3 is obtained when filll is
used.

The commands `\gluetomu`, `\mutoglue` read and return some glue. The
eTeX manual says: glue is converted into muglue and vice versa by simply
equating 1pt with 1mu. In the example here we use the commands described
above, and store them somewhere.

::: {.container .ltx-source}
    \muskip0 = 18mu plus 36mu minus 1 fill
    \skip0 = 10pt plus 20pt minus 1 fil
    \edef\uselater{%
    \the\muskip0,%
    \the\mutoglue\muskip0,%
    \the\skip0,%
    \the\gluetomu\skip0,%
    \the\mutoglue\gluetomu\skip0,%
    \the\glueshrink\skip0,%
    \the\gluestretch\skip0,%
    \the\glueshrinkorder\skip0,%
    \the\gluestretchorder\skip0}
:::

The command `\xoo` defined here contains the same characters as
`\uselater`. The non-trivial point is that all characters produced by
`\the` are of category code 12.

::: {.container .ltx-source}
    {\let\GDEF\gdef\let\XDEF\xdef\def\S{ }
     \catcode`m=12 \catcode`u=12 \catcode`p=12 \catcode`f=12  
     \catcode`i=12  \catcode`l=12 \catcode`n=12 \catcode`i=12 \catcode`s=12 
     \catcode`t=12 
     \GDEF\MU{mu}\GDEF\PT{pt}\GDEF\FIL{fil}\GDEF\FILL{fill}%
     \GDEF\PLUS{plus}\GDEF\MINUS{minus}
    \XDEF\xoo{18.0\MU\S \PLUS\S 36.0\MU\S \MINUS\S 1.0\FILL,%
    18.0\PT\S \PLUS\S 36.0\PT\S \MINUS\S 1.0\FILL,%
    10.0\PT\S \PLUS\S 20.0\PT\S \MINUS\S 1.0\FIL,% 
    10.0\MU\S \PLUS\S 20.0\MU\S \MINUS\S 1.0\FIL,%
    10.0\PT\S \PLUS\S 20.0\PT\S \MINUS\S 1.0\FIL,%
    1.0\PT,20.0\PT,1,0}}
:::

The command `\yoo` defined here contains the same characters and same
category codes as `\uselater`.

::: {.container .ltx-source}
    \edef\yoo{\detokenize{18.0mu plus 36.0mu minus 1.0fill,%
    18.0pt plus 36.0pt minus 1.0fill,%
    10.0pt plus 20.0pt minus 1.0fil,% 
    10.0mu plus 20.0mu minus 1.0fil,%
    10.0pt plus 20.0pt minus 1.0fil,%
    1.0pt,20.0pt,1,0}}
    \ifx\yoo\xoo\else\bad\fi
:::

\\gluetomu (e-TeX extension) {#cmd-gluetomu}
----------------------------

Inverse function of `` `\mutoglue `` \<doc-m.html\#cmd-mutoglue\>\`\_\_
(See above for an example).

\\gnapprox (math symbol) {#cmd-gnapprox}
------------------------

The `\gnapprox` command is valid only in math mode; it is a variant of
the greater-or-equal symbol: `<mo>&gnapprox;</mo>` (Unicode U+2A8A, ⪊).

\\gneq (math symbol) {#cmd-gneq}
--------------------

The `\gneq` command is valid only in math mode; it is a variant of the
greater-or-equal symbol: `<mo>&gneq;</mo>` (Unicode U+2A88, ⪈).

\\gneqq (math symbol) {#cmd-gneqq}
---------------------

The `\geqq` command is valid only in math mode; it is a variant of the
greater-or-equal symbol: `<mo>&gneqq;</mo>` (Unicode U+2269, ≩).

\\gnsim (math symbol) {#cmd-gnsim}
---------------------

The `\gnsim` command is valid only in math mode; it is a variant of the
greater-or-equal symbol: `<mo>&gnsim;</mo>` (Unicode U+22E7, ⋧).

\\\@gobble, \\\@gobbletwo, \\\@gobblefour {#cmd-gobble}
-----------------------------------------

The `\@gobble` command reads one argument and does nothing with it. In
the same fashion `\@gobbletwo` and `\@gobblefour` read two and four
arguments.

\\goodbreak {#cmd-goodbreak}
-----------

In *Tralics*, the `\goodbreak` command is the same as `\par`. In LaTeX,
it adds also some penalty (value -500).

\\grabenv (Tralics command) {#cmd-grabenv}
---------------------------

Inside an environment, you can say `\grabenv\foo`; in this case,
*Tralics* will collect all tokens until finding the end of the
environment, and put them (globally) in the command `\foo`. In the
following example, the last line produces two errors, because because
`\grabenv` is not followed by a valid command name and is outside an
environment.

::: {.container .ltx-source}
    \newenvironment {simple}{A}{B} 
    \newenvironment {grab}{C}{D\grabbed} 

    Test grabenv
    \begin{grab}x\grabenv\grabbed \begin{simple}yz\end{simple}t\end{grab}
    \grabbed=\grabenv.OK
:::

::: {.container .xml_out}
    Test grabenv
    CxDAyzBt
    AyzBt=<error n='\grabenv' l='180' c='bad definition'/><error n='\grabenv' l='180' c='\grabenv must be used in an environment'/>OK.
:::

\\grave {#cmd-grave}
-------

The `\grave` command puts a grave accent over a kernel. It works only in
math mode. See also the `` `\acute `` \<doc-a.html\#cmd-acute\>\`\_\_
command.

\\gtrapprox (math symbol) {#cmd-gtrapprox}
-------------------------

The `\gtrapprox` is valid in math mode only; translation is
`<mo>&gtrapprox;</mo>` (Unicode U+2A86, ⪆).

\\gtrdot (math symbol) {#cmd-gtrdot}
----------------------

The `\gtrdot` is valid in math mode only; translation is
`<mo>&gtrdot;</mo>` (Unicode U+22D7, ⋗).

\\gtreqless (math symbol) {#cmd-gtreqless}
-------------------------

The `\gtreqless` is valid in math mode only; translation is
`<mo>&gtreqless;</mo>` (Unicode U+22DB, ⋛).

\\gtreqqless (math symbol) {#cmd-gtreqqless}
--------------------------

The `\gtreqqless` is valid in math mode only; translation is
`<mo>&gtreqqless;</mo>` (Unicode U+2A8C, ⪌).

\\gtrless (math symbol) {#cmd-gtrless}
-----------------------

The `\gtrless` command gives a greater/less than symbol. It works only
in math mode: `<mo>&gtrless;</mo>` (Unicode U+2277, ≷). See also
description of the `` `\smallint `` \<doc-s.html\#cmd-smallint\>\`\_\_
command.

\\gtrsim (math symbol) {#cmd-gtrsim}
----------------------

The `\gtrsim` is valid in math mode only; translation is
`<mo>&gtrsim;</mo>` (Unicode U+2273, ≳).

guillemets (environment) {#cmd-guillemets}
------------------------

If you say `\begin{guillemets}xxx\end{guillemets}`, it is the same as if
you had said `«xxx»`. But in a future version of the software the
environment may produce much nicer results.

\\guillemotleft {#cmd-guillemotleft}
---------------

The `\guillemotleft` command translates into `«` or `&#xAB;`. For more
info see the [latin supplement characters](doc-chars.html#latin).

\\guillemotright {#cmd-guillemotright}
----------------

The `\guillemotright` command translates into `»` or `&#xBB;`. For more
info see the [latin supplement characters](doc-chars.html#latin).

\\gsavekeys, \\gdelsavekeys, \\gunsavekeys {#cmd-gsavekeys}
------------------------------------------

These commands are provided by the [xkeyval](doc-k.html#cmd-keyval)
package.

\\gpresetkeys, \\gdelpresetkeys, \\gunpresetkeys {#cmd-gpresetkeys}
------------------------------------------------

These commands are provided by the [xkeyval](doc-k.html#cmd-keyval)
package.
