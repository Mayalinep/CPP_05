# Expliquer une ligne de code
_Exported on 11/26/2025 at 15:21:05 GMT+1 from Cursor (2.1.17)_

---

**User**

tu peux me rexpiquer comment cete ligne fonctionne ? @ex00/Bureaucrat.hpp:21-24 

---

**Cursor**

Analyse du fichier pour comprendre le contexte, puis explication de ces lignes.


Explication de ces lignes :

```21:24:ex00/Bureaucrat.hpp
class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
};
```

## Explication détaillée

### 1. Classe imbriquée (nested class)
`GradeTooHighException` est définie à l’intérieur de `Bureaucrat`. Elle est liée à cette classe et peut être utilisée comme `Bureaucrat::GradeTooHighException`.

### 2. Héritage de `std::exception`
```cpp
: public std::exception
```
- Hérite de la classe de base standard pour les exceptions.
- Permet d’utiliser `catch (const std::exception& e)` pour la capturer.

### 3. La méthode `what()`
```cpp
const char* what() const throw();
```
- `const char*` : retourne une chaîne C (message d’erreur).
- `const` : la méthode ne modifie pas l’objet.
- `throw()` : spécification d’exception (C++98/03) indiquant que la méthode ne lance pas d’exception. Dépréciée en C++11, remplacée par `noexcept`.

### 4. Utilisation dans le code
Dans `Bureaucrat.cpp`, cette exception est lancée quand le grade est invalide :

```9:10:ex00/Bureaucrat.cpp
if(grade < 1)
	throw GradeTooHighException();
```

```30:31:ex00/Bureaucrat.cpp
if(_grade - 1 < 1)
	throw GradeTooHighException();
```

## Points à retenir
1. Classes d’exception personnalisées : créer des types d’exceptions spécifiques à votre domaine.
2. Héritage de `std::exception` : permet une gestion uniforme via `catch (const std::exception& e)`.
3. `what()` : méthode virtuelle de `std::exception` à redéfinir pour retourner un message.
4. Classes imbriquées : utiles pour des exceptions liées à une classe spécifique.

## Pour aller plus loin
- Remplacer `throw()` par `noexcept` en C++11+.
- Utiliser `std::string` pour le message (attention à la durée de vie).
- Voir aussi `std::runtime_error` et `std::logic_error` pour des cas plus spécifiques.

Souhaitez-vous que je détaille un point précis ?

```plaintext
class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
};
```

```cpp
: public std::exception
```

```cpp
const char* what() const throw();
```

```cpp
if(grade < 1)
	throw GradeTooHighException();
```

```cpp
if(_grade - 1 < 1)
	throw GradeTooHighException();
```

---

**User**

j ai essayer de commenrcer  ex01 tu veux bien m accompagner a comprendre mes erreurs petit a petit? je n ai fais que e form.hpp

---

**Cursor**

Analyse de `Form.hpp` et du sujet pour identifier les erreurs et les expliquer.


Analyse de `Form.hpp` pour identifier et expliquer les erreurs.

## Erreurs identifiées

### 1. Syntaxe de `const` (lignes 9, 11, 12, 16)

**Ligne 9 :** `std::string _name const;`  
**Ligne 11 :** `int _gradeSign const;`  
**Ligne 12 :** `in _gradeExec const;` (typo "in" → "int")

**Problème :** En C++, `const` se place avant le type, pas après.

**Correct :**
```cpp
const std::string _name;
const int _gradeSign;
const int _gradeExec;
```

**Pourquoi :** `const` qualifie le type. On lit "const std::string" (chaîne constante), pas "std::string const".

---

### 2. Ligne 10 : fonction `signed`

```cpp
bool signed(int _gradeSign, const Form& rhs);
```

**Problèmes :**
- `signed` est un mot-clé réservé en C++.
- D’après le sujet, `beSigned()` est une fonction membre qui prend un `Bureaucrat`, pas ces paramètres.
- Le statut de signature doit être un attribut booléen, pas une fonction.

**Correct :** Un attribut booléen privé :
```cpp
bool _isSigned;
```

---

### 3. Ligne 12 : typo

`in _gradeExec const;` → `int _gradeExec const;` (et corriger la position de `const`).

---

### 4. Ligne 16 : constructeur

```cpp
Form(std::string _name const, int _gradeSign const, int _gradeExec const);
```

**Problèmes :**
- `const` mal placé dans les paramètres.
- Les paramètres ne doivent pas avoir le préfixe `_` (réservé aux membres).

**Correct :**
```cpp
Form(const std::string& name, int gradeSign, int gradeExec);
```

**Note :** Les paramètres sont passés par référence const pour `std::string` (évite la copie), et par valeur pour les entiers.

---

### 5. Lignes 21 et 24 : pointeur `const char*`

```cpp
const *char what() const throw();
```

**Problème :** L’ordre est incorrect. C’est `const char*` (pointeur vers un caractère constant), pas `const *char`.

**Correct :**
```cpp
const char* what() const throw();
```

**Astuce :** Lire de droite à gauche : "pointeur vers char constant".

---

### 6. Ligne 23 : typo dans le nom de classe

`GradetooLowException` → `GradeTooLowException` (majuscule manquante).

---

### 7. Lignes 20-25 : structure des classes d’exception

**Problème :** Il manque `public:` dans les classes d’exception.

**Correct :**
```cpp
class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
};
```

---

### 8. Ligne 28 : getter incomplet

```cpp
int getGradeExec const;
```

**Problème :** Il manque les parenthèses `()`.

**Correct :**
```cpp
int getGradeExec() const;
```

---

### 9. Ligne 31 : `beSigned()` mal placée

```cpp
void beSigned(const Bureaucrat& bu, const Form& rhs);
```

**Problèmes :**
- C’est une fonction membre de `Form`, pas une fonction libre.
- Elle ne doit prendre qu’un `Bureaucrat` en paramètre (pas `Form& rhs`).

**Correct :** À mettre dans la section `public:` de `Form` :
```cpp
void beSigned(const Bureaucrat& bureaucrat);
```

---

## Récapitulatif des concepts

1. `const` : se place avant le type (`const int`, pas `int const`).
2. Mots-clés réservés : éviter `signed` comme nom.
3. Pointeurs : `const char*` (pointeur vers char constant).
4. Fonctions membres : `beSigned()` doit être dans la classe `Form`.
5. Conventions de nommage : pas de `_` sur les paramètres.

## Prochaine étape

Souhaitez-vous que je vous propose un `Form.hpp` corrigé pour comparer, ou préférez-vous corriger vous-même en vous basant sur ces points ?

```cpp
const std::string _name;
const int _gradeSign;
const int _gradeExec;
```

```cpp
bool signed(int _gradeSign, const Form& rhs);
```

```cpp
bool _isSigned;
```

```cpp
Form(std::string _name const, int _gradeSign const, int _gradeExec const);
```

```cpp
Form(const std::string& name, int gradeSign, int gradeExec);
```

```cpp
const *char what() const throw();
```

```cpp
const char* what() const throw();
```

```cpp
class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
};
```

```cpp
int getGradeExec const;
```

```cpp
int getGradeExec() const;
```

```cpp
void beSigned(const Bureaucrat& bu, const Form& rhs);
```

```cpp
void beSigned(const Bureaucrat& bureaucrat);
```

---

**User**

oui montre moi un corrige.. jss ds je maitrise pas bien 

---

**Cursor**

Vérification de votre version actuelle, puis proposition d’un corrigé complet avec explications.


Voici une version corrigée de `Form.hpp` avec des explications :

```cpp
#pragma once

#include <iostream>
#include <exception>
#include <string>

// Forward declaration - on déclare que Bureaucrat existe
// sans inclure tout le fichier (évite les dépendances circulaires)
class Bureaucrat;

class Form {
	private:
		const std::string _name;        // Nom constant du formulaire
		bool _isSigned;                 // Statut de signature (false par défaut)
		const int _gradeSign;           // Grade requis pour signer
		const int _gradeExec;           // Grade requis pour exécuter

	public:
		// Constructeurs et destructeur
		Form();
		Form(const std::string& name, int gradeSign, int gradeExec);
		Form(const Form& rhs);
		Form& operator=(const Form& rhs);
		~Form();

		// Classes d'exception imbriquées
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};  // ⚠️ Point-virgule OBLIGATOIRE après la classe

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};  // ⚠️ Point-virgule OBLIGATOIRE après la classe

		// Getters (accesseurs)
		std::string getName() const;
		bool getIsSigned() const;       // Getter pour savoir si signé
		int getGradeSign() const;
		int getGradeExec() const;

		// Fonction membre pour signer le formulaire
		void beSigned(const Bureaucrat& bureaucrat);
};

// Surcharge de l'opérateur << pour afficher le formulaire
std::ostream& operator<<(std::ostream& os, const Form& form);
```

## Corrections apportées

### 1. Attribut `_isSigned` (ligne 11)
- Avant : `bool isSigned(int _gradeSign, const Form& rhs);` (fonction)
- Après : `bool _isSigned;` (attribut booléen)
- Pourquoi : le statut de signature est un attribut, pas une fonction.

### 2. Typos corrigées (lignes 11-12)
- `coonst` → `const`
- `cont` → `const`

### 3. Constructeur (ligne 16)
- Avant : `Form(const std::string& name, const int gradeSign, const int gradeExec);`
- Après : `Form(const std::string& name, int gradeSign, int gradeExec);`
- Pourquoi : les paramètres entiers n’ont pas besoin d’être `const` (copies). `const` est pour les membres.

### 4. Point-virgules après les classes (lignes 23, 27)
- Ajout de `;` après chaque classe d’exception.
- En C++, une déclaration de classe se termine par `;`.

### 5. Forward declaration de `Bureaucrat` (ligne 8)
- `class Bureaucrat;` permet d’utiliser `Bureaucrat&` dans le header sans inclure `Bureaucrat.hpp`.
- L’include sera fait dans `Form.cpp`.

### 6. Getter `getIsSigned()` (ligne 30)
- Ajout d’un getter pour vérifier si le formulaire est signé.

## Points à retenir

1. Attributs vs fonctions : `_isSigned` est un attribut, pas une fonction.
2. Syntaxe `const` : `const int _gradeSign` (pas `int _gradeSign const`).
3. Point-virgule : obligatoire après une déclaration de classe.
4. Forward declaration : utile pour éviter les dépendances circulaires.
5. Conventions : membres privés avec `_`, paramètres sans `_`.

## Prochaine étape

Souhaitez-vous que je vous guide pour `Form.cpp` ? Je peux vous aider à comprendre comment implémenter chaque fonction.

Copiez ce code dans votre `Form.hpp` et dites-moi si vous avez des questions.

```cpp
#pragma once

#include <iostream>
#include <exception>
#include <string>

// Forward declaration - on déclare que Bureaucrat existe
// sans inclure tout le fichier (évite les dépendances circulaires)
class Bureaucrat;

class Form {
	private:
		const std::string _name;        // Nom constant du formulaire
		bool _isSigned;                 // Statut de signature (false par défaut)
		const int _gradeSign;           // Grade requis pour signer
		const int _gradeExec;           // Grade requis pour exécuter

	public:
		// Constructeurs et destructeur
		Form();
		Form(const std::string& name, int gradeSign, int gradeExec);
		Form(const Form& rhs);
		Form& operator=(const Form& rhs);
		~Form();

		// Classes d'exception imbriquées
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};  // ⚠️ Point-virgule OBLIGATOIRE après la classe

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};  // ⚠️ Point-virgule OBLIGATOIRE après la classe

		// Getters (accesseurs)
		std::string getName() const;
		bool getIsSigned() const;       // Getter pour savoir si signé
		int getGradeSign() const;
		int getGradeExec() const;

		// Fonction membre pour signer le formulaire
		void beSigned(const Bureaucrat& bureaucrat);
};

// Surcharge de l'opérateur << pour afficher le formulaire
std::ostream& operator<<(std::ostream& os, const Form& form);
```

---

**User**

merci bcp t es super chouette :)

---

**Cursor**

Merci, c’est gentil.

Vous progressez bien. Les erreurs que vous avez faites sont courantes quand on débute en C++ (syntaxe `const`, point-virgules, attributs vs fonctions). Avec la pratique, cela devient naturel.

Quand vous serez prête pour `Form.cpp`, je peux vous guider étape par étape :
- Implémenter les constructeurs
- Gérer les exceptions
- Implémenter `beSigned()`
- Surcharger l’opérateur `<<`

N’hésitez pas si vous avez des questions. Bon courage pour la suite.

---

**User**

merci de m encourager.  est ce que vous pouvez revoir avec moi sans me donner la reponse ce que le sujet attend de moi?

---

**Cursor**

Relisant le sujet pour identifier ce qui est attendu, puis on analysera ensemble.


Analysons le sujet ensemble, étape par étape. Je vous pose des questions pour vous guider.

## Analyse du sujet — questions guidées

### 1. Les attributs de la classe Form (lignes 11-14)

Le sujet dit que Form doit avoir :
- Un nom constant
- Un booléen indiquant s'il est signé (pas signé à la construction)
- Un grade constant requis pour signer
- Un grade constant requis pour exécuter

Questions :
- Pourquoi le nom et les grades sont-ils `const` ?
- À quelle valeur initiale doit être le booléen à la construction ?
- Dans votre `Form.hpp`, avez-vous bien ces 4 attributs ? (Je vois quelques petites erreurs de syntaxe à corriger ensuite)

---

### 2. Les règles des grades (ligne 18)

Le sujet dit : "The grades of the Form follow the same rules as those of the Bureaucrat."

Questions :
- Dans `Bureaucrat`, quelles sont les règles pour les grades ? (plage valide ?)
- Quand doit-on lancer `GradeTooHighException` ?
- Quand doit-on lancer `GradeTooLowException` ?
- Où dans votre code devez-vous vérifier ces règles ? (constructeur ? ailleurs ?)

---

### 3. Les getters et l'opérateur << (lignes 23-24)

Le sujet demande : "write getters for all attributes and overload the insertion (<<) operator"

Questions :
- Quels getters devez-vous créer ? (un par attribut)
- Que doit afficher l'opérateur `<<` ? (tous les attributs du formulaire)
- Regardez comment vous avez fait pour `Bureaucrat` dans ex00 — pouvez-vous vous en inspirer ?

---

### 4. La fonction `beSigned()` (lignes 26-29)

Le sujet dit : "add a beSigned() member function to the Form that takes a Bureaucrat as a parameter"

Questions :
- Où doit être cette fonction ? (dans Form ou Bureaucrat ?)
- Que doit-elle faire si le grade du bureaucrate est suffisant ?
- Que doit-elle faire si le grade est trop bas ?
- Important : "grade 1 is higher than grade 2" — donc un grade plus petit = plus élevé. Si le formulaire nécessite grade 5, un bureaucrate de grade 3 peut-il signer ? Et un bureaucrate de grade 7 ?

---

### 5. La fonction `signForm()` dans Bureaucrat (lignes 30-34)

Le sujet dit : "modify the signForm() member function in the Bureaucrat class"

Questions :
- Cette fonction doit être ajoutée dans quelle classe ? (Bureaucrat)
- Que doit-elle faire ? (appeler `beSigned()` du formulaire)
- Que doit-elle afficher si la signature réussit ?
- Que doit-elle afficher si la signature échoue ?
- Comment récupérer la raison de l'échec ? (exception)

---

## Réflexion globale

- Quelles sont les interactions entre `Bureaucrat` et `Form` ?
- Qui fait quoi : qui vérifie le grade, qui change le statut de signature, qui affiche les messages ?

Répondez à ces questions, et on verra ensemble si tout est clair. Si vous bloquez sur une question, dites-le et on creusera.

---

**User**

1. on fait des const pour eviter que cela soit modifier. le booleen aura a valeur false.  oui j ai les 4 attributs.

2. que e grade est compris entre 1-150 et endehors ca n existe pas. que le grade le + eleve c est   1 et le plus bas c est 150.  gradetoohigh exception doit etre lancer si le grade du Bureaucrat est trop grand pour signer ? et gradetooowexception c est e contraire ?

je dois verifier lors de la construction de form et au moment de besigned(const Bureaucrat& bu).

3. je dois creer un getter par attribut, operator<< dois afficher les info de form 

4.da fonction besigned soit etre dans a class de form 

si le grade est suffisant elle signe sinn elle signe pas

si e bureaucrat a un grade e ca et que ca existe un grade 5 il peut signer sinn si cest 7 il peut pas signer.

5. je sais pas c estr quoi le signform ()



je comprend pas trop es interation entre bureaucrat et form surtt je voudrai comprendre en terme d exempe pour comprendre aavec un cas concret es actions es roles des attributs. form ca veut dire formuaire ou signature je comprend pas 

---

**Cursor**


Clarifions avec un exemple concret, puis on corrige les points à ajuster.



## Exemple concret : scénario administratif

Imaginez une administration avec des formulaires à signer.

### Les personnages
- Bureaucrat = un fonctionnaire avec un grade (1 = très haut, 150 = bas)
- Form = un formulaire administratif (ex. demande de permis, déclaration)

### Exemple concret

```cpp
// On crée un formulaire "Demande de permis de construire"
// Ce formulaire nécessite un grade minimum de 5 pour être signé
Form permis("Demande de permis", 5, 10);
// _name = "Demande de permis"
// _gradeSign = 5 (il faut au moins grade 5 pour signer)
// _gradeExec = 10 (il faut au moins grade 10 pour exécuter)
// _isSigned = false (pas encore signé)

// On crée deux bureaucrates
Bureaucrat chef("Marie", 3);      // Grade 3 = très haut niveau
Bureaucrat stagiaire("Jean", 80); // Grade 80 = bas niveau
```

### Scénario 1 : le chef peut signer

```cpp
// Le chef (grade 3) veut signer le formulaire (nécessite grade 5)
// Grade 3 < 5 ? OUI ! Donc le chef peut signer (grade plus petit = plus élevé)
permis.beSigned(chef);
// Résultat : _isSigned devient true ✅
```

### Scénario 2 : le stagiaire ne peut pas signer

```cpp
// Le stagiaire (grade 80) veut signer le formulaire (nécessite grade 5)
// Grade 80 < 5 ? NON ! Donc le stagiaire ne peut PAS signer
permis.beSigned(stagiaire);
// Résultat : exception GradeTooLowException lancée ❌
```

---

## Corrections importantes

### 1. Les exceptions — attention, vous avez inversé

Regardez votre code de Bureaucrat :

```9:12:ex00/Bureaucrat.cpp
if(grade < 1)
	throw GradeTooHighException();
if(grade > 150)
	throw GradeTooLowException();
```

- Grade < 1 → `GradeTooHighException` (trop haut = invalide)
- Grade > 150 → `GradeTooLowException` (trop bas = invalide)

Pour Form, c'est la même logique :
- Si on crée un Form avec `gradeSign < 1` → `GradeTooHighException`
- Si on crée un Form avec `gradeSign > 150` → `GradeTooLowException`

Dans `beSigned()` :
- Si le bureaucrate a un grade trop bas (trop grand numériquement) pour signer → `GradeTooLowException`

Exemple :
```cpp
Form f("Test", 5, 10);  // Nécessite grade 5
Bureaucrat b("Jean", 80); // Grade 80
f.beSigned(b); // Grade 80 > 5, donc trop bas → GradeTooLowException
```

---

### 2. La fonction `signForm()` dans Bureaucrat

Le sujet demande d'ajouter une fonction dans Bureaucrat qui permet au bureaucrate de signer un formulaire.

```cpp
// Dans Bureaucrat.hpp, vous devez ajouter :
void signForm(Form& form);
```

Cette fonction :
1. Appelle `form.beSigned(*this)` (le bureaucrate essaie de signer le formulaire)
2. Si ça réussit : affiche "<bureaucrat> signed <form>"
3. Si ça échoue (exception) : affiche "<bureaucrat> couldn't sign <form> because <reason>"

Exemple d'utilisation :
```cpp
Bureaucrat chef("Marie", 3);
Form permis("Demande de permis", 5, 10);

chef.signForm(permis);
// Affiche : "Marie signed Demande de permis"
// OU si échec : "Marie couldn't sign Demande de permis because grade too low"
```

---

## Récapitulatif des rôles

| Qui | Fait quoi | Où |
|-----|-----------|-----|
| **Form** | Stocke les informations du formulaire | Form.hpp/cpp |
| **Form::beSigned()** | Vérifie si le bureaucrate peut signer, change `_isSigned` à `true` si oui | Dans Form |
| **Bureaucrat::signForm()** | Appelle `beSigned()` et affiche un message de succès/échec | Dans Bureaucrat |

---

## Questions pour vérifier votre compréhension

1. Si un Form nécessite grade 10, un bureaucrate de grade 8 peut-il signer ? Pourquoi ?
2. Dans `beSigned()`, que devez-vous comparer exactement ?
3. Où devez-vous ajouter `signForm()` ? Dans quel fichier ?

Dites-moi vos réponses et on ajuste si besoin.

```cpp
// On crée un formulaire "Demande de permis de construire"
// Ce formulaire nécessite un grade minimum de 5 pour être signé
Form permis("Demande de permis", 5, 10);
// _name = "Demande de permis"
// _gradeSign = 5 (il faut au moins grade 5 pour signer)
// _gradeExec = 10 (il faut au moins grade 10 pour exécuter)
// _isSigned = false (pas encore signé)

// On crée deux bureaucrates
Bureaucrat chef("Marie", 3);      // Grade 3 = très haut niveau
Bureaucrat stagiaire("Jean", 80); // Grade 80 = bas niveau
```

```cpp
// Le chef (grade 3) veut signer le formulaire (nécessite grade 5)
// Grade 3 < 5 ? OUI ! Donc le chef peut signer (grade plus petit = plus élevé)
permis.beSigned(chef);
// Résultat : _isSigned devient true ✅
```

```cpp
// Le stagiaire (grade 80) veut signer le formulaire (nécessite grade 5)
// Grade 80 < 5 ? NON ! Donc le stagiaire ne peut PAS signer
permis.beSigned(stagiaire);
// Résultat : exception GradeTooLowException lancée ❌
```

```cpp
if(grade < 1)
	throw GradeTooHighException();
if(grade > 150)
	throw GradeTooLowException();
```

```cpp
Form f("Test", 5, 10);  // Nécessite grade 5
Bureaucrat b("Jean", 80); // Grade 80
f.beSigned(b); // Grade 80 > 5, donc trop bas → GradeTooLowException
```

```cpp
// Dans Bureaucrat.hpp, vous devez ajouter :
void signForm(Form& form);
```

```cpp
Bureaucrat chef("Marie", 3);
Form permis("Demande de permis", 5, 10);

chef.signForm(permis);
// Affiche : "Marie signed Demande de permis"
// OU si échec : "Marie couldn't sign Demande de permis because grade too low"
```

---

**User**

mais je comprend pas la difference entre gradesign et grade exec ? a quoi sert ou a quel moment on utilise gradeexec

---

**Cursor**


Explication de la différence entre `gradeSign` et `gradeExec` avec un exemple concret.



## Différence entre `gradeSign` et `gradeExec`

### Exemple concret : un formulaire administratif

Imaginez un formulaire "Ordre de démolition d'un bâtiment" :

```cpp
Form demolition("Ordre de démolition", 10, 5);
// _gradeSign = 10  (nécessite grade 10 pour SIGNER)
// _gradeExec = 5   (nécessite grade 5 pour EXÉCUTER)
```

### Les deux étapes

1. Signer le formulaire (`gradeSign`)
   - Un bureaucrate de grade 10 peut signer.
   - Un bureaucrate de grade 15 ne peut pas signer.
   - Action : approuver le document.

2. Exécuter le formulaire (`gradeExec`)
   - Un bureaucrate de grade 5 peut exécuter.
   - Un bureaucrate de grade 8 ne peut pas exécuter.
   - Action : réaliser l'action (démolir, autoriser, etc.).

### Pourquoi deux grades différents ?

- Signer = approuver (souvent un niveau hiérarchique moyen).
- Exécuter = agir (souvent un niveau plus élevé).

Exemple :
- Un chef de service (grade 10) peut signer.
- Un directeur (grade 5) doit exécuter.

---

## Dans l'exercice ex01

Dans ex01, vous n'utilisez que `gradeSign` pour `beSigned()`. `gradeExec` n'est pas encore utilisé, mais il doit être présent dans la classe car il sera utilisé dans les exercices suivants (ex02, ex03, etc.).

### Ce que vous devez faire dans ex01

1. Créer les deux attributs : `_gradeSign` et `_gradeExec`
2. Vérifier les deux lors de la construction (lancer des exceptions si invalides)
3. Créer les getters pour les deux
4. Utiliser uniquement `gradeSign` dans `beSigned()`
5. Afficher les deux dans l'opérateur `<<`

---

## Questions pour vérifier

1. Si un Form a `gradeSign = 20` et `gradeExec = 5`, qui peut signer ? Qui peut exécuter ?
2. Dans `beSigned()`, quel grade devez-vous comparer avec le grade du bureaucrate ?
3. Pourquoi le sujet demande-t-il `gradeExec` même si on ne l'utilise pas encore dans ex01 ?

---

## Récapitulatif

| Attribut | Utilisé dans ex01 ? | À quoi ça sert ? |
|----------|---------------------|------------------|
| `_gradeSign` | Oui, dans `beSigned()` | Vérifier si on peut signer |
| `_gradeExec` | Non (mais doit exister) | Sera utilisé plus tard pour exécuter |

En résumé : dans ex01, `gradeExec` doit exister et être validé, mais il n'est pas encore utilisé. Il servira dans les exercices suivants.

Avez-vous d'autres questions sur cette distinction ?

```cpp
Form demolition("Ordre de démolition", 10, 5);
// _gradeSign = 10  (nécessite grade 10 pour SIGNER)
// _gradeExec = 5   (nécessite grade 5 pour EXÉCUTER)
```

