
;; Added by Package.el.  This must come before configurations of
;; installed packages.  Don't delete this line.  If you don't want it,
;; just comment it out by adding a semicolon to the start of the line.
;; You may delete these explanatory comments.
(package-initialize)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(ansi-color-names-vector
   ["#2d3743" "#ff4242" "#74af68" "#dbdb95" "#34cae2" "#008b8b" "#00ede1" "#e1e1e0"])
 '(custom-enabled-themes (quote (misterioso)))
 '(custom-safe-themes
   (quote
    ("e52718d4b950106873fed00c469941ad8db20f02392d2c7ac184c6defe37ad2c" "68e8f9d3bfe2d684d21ef5bbacedf4e80c93583e270626d27e985f1dc9d2d1b4" "d3a66510c8b7992ce795d290140eaaddc9e3ad24907f6c659b7f8ebca3f41f87" "c3c0a3702e1d6c0373a0f6a557788dfd49ec9e66e753fb24493579859c8e95ab" default)))
 '(font-use-system-font t)
 '(inhibit-startup-screen t)
 '(save-place-mode t)
 '(show-paren-mode t)
 '(tool-bar-mode nil))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:inherit nil :stipple nil :background "#242634" :foreground "#F8F8F2" :inverse-video nil :box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 128 :width normal :foundry "DAMA" :family "Ubuntu Mono")))))
(tool-bar-mode 0)
;;(menu-bar-mode 0)
(scroll-bar-mode 0)
(show-paren-mode t)
(global-linum-mode 1)
(set-frame-parameter (selected-frame) 'alpha (list 90 90))
(add-to-list 'default-frame-alist (cons 'alpha (list 90 90)))
(set-cursor-color "#20B2AA")
(add-to-list 'custom-theme-load-path "~/.emacs.d/themes/")
(setq molokai-theme-kit t)
(load-theme 'monokai t)

(setq-default cursor-type 'blink)

(define-key ctl-x-map "l" 'goto-line) 
