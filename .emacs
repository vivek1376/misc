(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-safe-themes (quote ("fc5fcb6f1f1c1bc01305694c59a1a861b008c534cae8d0e48e4d5e81ad718bc6" "ef43b291f7e96826d3d9bae61434a93020d0f529d609bc8be5b331980e8448d7" "1e7e097ec8cb1f8c3a912d7e1e0331caeed49fef6cff220be63bd2a6ba4cc365" "9dae95cdbed1505d45322ef8b5aa90ccb6cb59e0ff26fef0b8f411dfc416c552" "8d6fb24169d94df45422617a1dfabf15ca42a97d594d28b3584dc6db711e0e0b" "49eea2857afb24808915643b1b5bd093eefb35424c758f502e98a03d0d3df4b1" default)))
 '(tool-bar-mode nil))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Ubuntu Mono" :foundry "unknown" :slant normal :weight normal :height 98 :width normal)))))
(global-set-key [f9] 'compile)

(require 'package)
(add-to-list 'package-archives
	     '("melpa" . "http://melpa.org/packages/") t)
(package-initialize)

(load-theme 'zenburn t)
(enable-theme 'zenburn)

(setq c-default-style "linux"
      c-basic-offset 4)

(add-hook 'c++-mode-hook
          (lambda () (setq comment-start "/* " comment-end " */")))









;; pasted by vivek
;;; google-c-style.el --- Google's C/C++ style for c-mode

;; Keywords: c, tools

;; google-c-style.el is Copyright (C) 2008 Google Inc. All Rights Reserved.
;;
;; It is free software; you can redistribute it and/or modify it under the
;; terms of either:
;;
;; a) the GNU General Public License as published by the Free Software
;; Foundation; either version 1, or (at your option) any later version, or
;;
;; b) the "Artistic License".

;;; Commentary:

;; Provides the google C/C++ coding style. You may wish to add
;; `google-set-c-style' to your `c-mode-common-hook' after requiring this
;; file. For example:
;;
;;    (add-hook 'c-mode-common-hook 'google-set-c-style)
;;
;; If you want the RETURN key to go to the next line and space over
;; to the right place, add this to your .emacs right after the load-file:
;;
;;    (add-hook 'c-mode-common-hook 'google-make-newline-indent)

;;; Code:

;; For some reason 1) c-backward-syntactic-ws is a macro and 2)  under Emacs 22
;; bytecode cannot call (unexpanded) macros at run time:
(eval-when-compile (require 'cc-defs))

;; Wrapper function needed for Emacs 21 and XEmacs (Emacs 22 offers the more
;; elegant solution of composing a list of lineup functions or quantities with
;; operators such as "add")
(defun google-c-lineup-expression-plus-4 (langelem)
  "Indents to the beginning of the current C expression plus 4 spaces.

This implements title \"Function Declarations and Definitions\"
of the Google C++ Style Guide for the case where the previous
line ends with an open parenthese.

\"Current C expression\", as per the Google Style Guide and as
clarified by subsequent discussions, means the whole expression
regardless of the number of nested parentheses, but excluding
non-expression material such as \"if(\" and \"for(\" control
structures.

Suitable for inclusion in `c-offsets-alist'."
  (save-excursion
    (back-to-indentation)
    ;; Go to beginning of *previous* line:
    (c-backward-syntactic-ws)
    (back-to-indentation)
    (cond
     ;; We are making a reasonable assumption that if there is a control
     ;; structure to indent past, it has to be at the beginning of the line.
     ((looking-at "\\(\\(if\\|for\\|while\\)\\s *(\\)")
      (goto-char (match-end 1)))
     ;; For constructor initializer lists, the reference point for line-up is
     ;; the token after the initial colon.
     ((looking-at ":\\s *")
      (goto-char (match-end 0))))
    (vector (+ 4 (current-column)))))

;;;###autoload
(defconst google-c-style
  `((c-recognize-knr-p . nil)
    (c-enable-xemacs-performance-kludge-p . t) ; speed up indentation in XEmacs
    (c-basic-offset . 2)
    (indent-tabs-mode . nil)
    (c-comment-only-line-offset . 0)
    (c-hanging-braces-alist . ((defun-open after)
                               (defun-close before after)
                               (class-open after)
                               (class-close before after)
                               (inexpr-class-open after)
                               (inexpr-class-close before)
                               (namespace-open after)
                               (inline-open after)
                               (inline-close before after)
                               (block-open after)
                               (block-close . c-snug-do-while)
                               (extern-lang-open after)
                               (extern-lang-close after)
                               (statement-case-open after)
                               (substatement-open after)))
    (c-hanging-colons-alist . ((case-label)
                               (label after)
                               (access-label after)
                               (member-init-intro before)
                               (inher-intro)))
    (c-hanging-semi&comma-criteria
     . (c-semi&comma-no-newlines-for-oneline-inliners
        c-semi&comma-inside-parenlist
        c-semi&comma-no-newlines-before-nonblanks))
    (c-indent-comments-syntactically-p . t)
    (comment-column . 40)
    (c-indent-comment-alist . ((other . (space . 2))))
    (c-cleanup-list . (brace-else-brace
                       brace-elseif-brace
                       brace-catch-brace
                       empty-defun-braces
                       defun-close-semi
                       list-close-comma
                       scope-operator))
    (c-offsets-alist . ((arglist-intro google-c-lineup-expression-plus-4)
                        (func-decl-cont . ++)
                        (member-init-intro . ++)
                        (inher-intro . ++)
                        (comment-intro . 0)
                        (arglist-close . c-lineup-arglist)
                        (topmost-intro . 0)
                        (block-open . 0)
                        (inline-open . 0)
                        (substatement-open . 0)
                        (statement-cont
                         .
                         (,(when (fboundp 'c-no-indent-after-java-annotations)
                             'c-no-indent-after-java-annotations)
                          ,(when (fboundp 'c-lineup-assignments)
                             'c-lineup-assignments)
                          ++))
                        (label . /)
                        (case-label . +)
                        (statement-case-open . +)
                        (statement-case-intro . +) ; case w/o {
                        (access-label . /)
                        (innamespace . 0))))
  "Google C/C++ Programming Style.")

;;;###autoload
(defun google-set-c-style ()
  "Set the current buffer's c-style to Google C/C++ Programming
  Style. Meant to be added to `c-mode-common-hook'."
  (interactive)
  (make-local-variable 'c-tab-always-indent)
  (setq c-tab-always-indent t)
  (c-add-style "Google" google-c-style t))

;;;###autoload
(defun google-make-newline-indent ()
  "Sets up preferred newline behavior. Not set by default. Meant
  to be added to `c-mode-common-hook'."
  (interactive)
  (define-key c-mode-base-map "\C-m" 'newline-and-indent)
  (define-key c-mode-base-map [ret] 'newline-and-indent))

(provide 'google-c-style)
;;; google-c-style.el ends here








;; pasted by vivek for astyle    url: http://stackoverflow.com/questions/801983/how-do-i-use-astyle-within-emacs
(defun astyle-this-buffer (pmin pmax)
  (interactive "r")
  (shell-command-on-region pmin pmax
                           "astyle -U -p -d -O -n" ;; add options here...
                           (current-buffer) t 
                           (get-buffer-create "*Astyle Errors*") t))
