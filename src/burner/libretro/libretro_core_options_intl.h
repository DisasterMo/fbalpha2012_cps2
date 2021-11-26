#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include <libretro.h>

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_JAPANESE */

/* RETRO_LANGUAGE_FRENCH */


struct retro_core_option_v2_category option_cats_fr[] = {
   { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_fr[] = {
   {
      "fba2012cps2_cpu_speed_adjust",
      "Vitesse CPU (%)",
      NULL,
      "Active l'overclocking du processeur émulé. Peut réduire le ralentissement, mais peut causer des problèmes.",
      NULL,
      NULL,
      {
         { "100", NULL },
         { "110", NULL },
         { "120", NULL },
         { "130", NULL },
         { "140", NULL },
         { "150", NULL },
         { "160", NULL },
         { "170", NULL },
         { "180", NULL },
         { "190", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "fba2012cps2_controls",
      "Les contrôles",
      NULL,
      "Définir le mappage par défaut des manettes.",
      NULL,
      NULL,
      {
         { "gamepad", "Gamepad" },
         { "arcade",  "Arcade" },
         { "newgen",  "Modern" },
         { NULL, NULL },
      },
      "gamepad"
   },
   {
      "fba2012cps2_frameskip",
      "Frameskip",
      NULL,
      "Sauter des images pour éviter que le tampon audio ne soit sous-exécuté (crépitements). Améliore les performances au détriment de la fluidité visuelle. 'Auto' saute des images lorsque le frontend le conseille. 'Manuel' utilise le paramètre 'Seuil de saut d'images (%)'.",
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     "Auto" },
         { "manual",   "Manual" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "fba2012cps2_frameskip_threshold",
      "Frameskip Threshold (%)",
      NULL,
      "Lorsque 'Saut d'images' est réglé sur 'Manuel', spécifie le seuil d'occupation du tampon audio (pourcentage) en dessous duquel des images seront sautées. Des valeurs plus élevées réduisent le risque de crépitements en faisant sauter des images plus fréquemment.",
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_fr = {
   option_cats_fr,
   option_defs_fr
};

/* RETRO_LANGUAGE_SPANISH */


struct retro_core_option_v2_category option_cats_es[] = {
   { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_es[] = {
   {
      "fba2012cps2_cpu_speed_adjust",
      "Velocidad de la CPU (%)",
      NULL,
      "Permite overclockear la CPU emulada. Puede reducir las ralentizaciones, pero podría provocar defectos visuales.",
      NULL,
      NULL,
      {
         { "100", NULL },
         { "110", NULL },
         { "120", NULL },
         { "130", NULL },
         { "140", NULL },
         { "150", NULL },
         { "160", NULL },
         { "170", NULL },
         { "180", NULL },
         { "190", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "fba2012cps2_hiscores",
      "Tablas de puntuaciones",
      NULL,
      "Permite guardar las tablas de las mejores puntuaciones en los juegos compatibles con esta función. Es necesario tener el archivo «hiscore.dat» en la carpeta system/fbalpha2012/.",
      NULL,
      NULL,
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "fba2012cps2_controls",
      "Controles",
      NULL,
      "Configura la asignación predeterminada de los mandos.",
      NULL,
      NULL,
      {
         { "gamepad", "Mando" },
         { "arcade",  "Arcade" },
         { NULL, NULL },
      },
      "gamepad"
   },
   {
      "fba2012cps2_aspect",
      "Relación de aspecto asignada por el núcleo",
      NULL,
      "Selecciona la relación de aspecto preferida para el contenido. Este ajuste solo se aplicará cuando la relación de aspecto de RetroArch esté configurada como «Asignada por el núcleo».",
      NULL,
      NULL,
      {
         { "DAR", NULL },
         { "PAR", NULL },
         { NULL, NULL },
      },
      "DAR"
   },
   {
      "fba2012cps2_auto_rotate",
      "Rotar los juegos con una alineación vertical (es necesario reiniciar)",
      NULL,
      "Rota automáticamente la imagen al ejecutar juegos con una alineación vertical. Al desactivar esta opción, la entrada de la cruceta se rotará para que coincida con las direcciones que aparezcan en pantalla.",
      NULL,
      NULL,
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "fba2012cps2_lowpass_filter",
      "Filtro de audio",
      NULL,
      "Utiliza un filtro de paso bajo de audio para suavizar las asperezas en el sonido de ciertos juegos arcade.",
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "fba2012cps2_lowpass_range",
      "Nivel del filtro de audio (%)",
      NULL,
      "Especifica el corte de frecuencias en el filtro de paso bajo de audio. Un valor elevado aumentará la fuerza percibida del filtro porque se atenuará un rango mayor del espectro de frecuencias altas.",
      NULL,
      NULL,
      {
         { "5",  NULL },
         { "10", NULL },
         { "15", NULL },
         { "20", NULL },
         { "25", NULL },
         { "30", NULL },
         { "35", NULL },
         { "40", NULL },
         { "45", NULL },
         { "50", NULL },
         { "55", NULL },
         { "60", NULL },
         { "65", NULL },
         { "70", NULL },
         { "75", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { NULL, NULL },
      },
      "60"
   },
   {
      "fba2012cps2_frameskip",
      "Omisión de fotogramas",
      NULL,
      "Omite fotogramas para no saturar el búfer de audio (chasquidos en el sonido). Mejora el rendimiento a costa de perder fluidez visual. El valor Automática omite fotogramas según lo aconseje el front-end. El valor Manual utiliza el ajuste Umbral de omisión de fotogramas (%).",
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     "Automática" },
         { "manual",   "Manual" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "fba2012cps2_frameskip_threshold",
      "Umbral de omisión de fotogramas (%)",
      NULL,
      "Cuando la omisión de fotogramas esté configurada como Manual, este ajuste especifica el umbral de ocupación del búfer de audio (en porcentaje) por el que se omitirán fotogramas si el valor es inferior. Un valor más elevado reduce el riesgo de chasquidos omitiendo fotogramas con una mayor frecuencia.",
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_es = {
   option_cats_es,
   option_defs_es
};

/* RETRO_LANGUAGE_GERMAN */

/* RETRO_LANGUAGE_ITALIAN */

/* RETRO_LANGUAGE_DUTCH */

/* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */

/* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */

/* RETRO_LANGUAGE_RUSSIAN */

/* RETRO_LANGUAGE_KOREAN */

/* RETRO_LANGUAGE_CHINESE_TRADITIONAL */

/* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */

/* RETRO_LANGUAGE_ESPERANTO */

/* RETRO_LANGUAGE_POLISH */

/* RETRO_LANGUAGE_VIETNAMESE */

/* RETRO_LANGUAGE_ARABIC */

/* RETRO_LANGUAGE_GREEK */

/* RETRO_LANGUAGE_TURKISH */


struct retro_core_option_v2_category option_cats_tr[] = {
   { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_tr[] = {
   {
      "fba2012cps2_cpu_speed_adjust",
      "CPU Hızı (%)",
      NULL,
      "Öykünmüş CPU'nun hız aşırtmasını sağlar. Yavaşlamayı azaltabilir, ancak hatalara neden olabilir.",
      NULL,
      NULL,
      {
         { "100", NULL },
         { "110", NULL },
         { "120", NULL },
         { "130", NULL },
         { "140", NULL },
         { "150", NULL },
         { "160", NULL },
         { "170", NULL },
         { "180", NULL },
         { "190", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "fba2012cps2_controls",
      "Kontroller",
      NULL,
      "Varsayılan denetleyici eşlemesini ayarlayın.",
      NULL,
      NULL,
      {
         { "gamepad", "Oyun kumandası" },
         { "arcade",  "Arcade" },
         { "newgen",  "Modern" },
         { NULL, NULL },
      },
      "gamepad"
   },
   {
      "fba2012cps2_frameskip",
      "Kare Atlama",
      NULL,
      "Yetersiz çalışan ses arabelleğini, çatırtı önlemek için kareleri atlar. Görsel pürüzsüzlük pahasına performansı iyileştirir. 'Otomatik', ön uç tarafından önerildiğinde kareleri atlar. 'El ile', 'Kara Atlama Eşiği (%)' ayarını kullanır.",
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     "Auto" },
         { "manual",   "Manual" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "fba2012cps2_frameskip_threshold",
      "Frameskip Threshold (%)",
      NULL,
      "Kare Atlama', 'El ile' olarak ayarlandığında, altındaki karelerin atlanacağı ses arabelleği doluluk eşiğini (yüzde olarak) belirtir. Daha yüksek değerler, karelerin daha sık düşmesine neden olarak çatlama riskini azaltır.",
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_tr = {
   option_cats_tr,
   option_defs_tr
};

/* RETRO_LANGUAGE_SLOVAK */

/* RETRO_LANGUAGE_PERSIAN */

/* RETRO_LANGUAGE_HEBREW */

/* RETRO_LANGUAGE_ASTURIAN */

#ifdef __cplusplus
}
#endif

#endif
