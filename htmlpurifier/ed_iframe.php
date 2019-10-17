<?php
/**
 * Specific domain whitelist for eDidiaktikum
 * Based on: http://sachachua.com/blog/2011/08/drupal-html-purifier-embedding-iframes-youtube/
 * Iframe filter that does some primitive whitelisting in a somewhat recognizable and tweakable way
 */
class HTMLPurifier_Filter_EdIframe extends HTMLPurifier_Filter
{
    public $name = 'edIframe';

    /**
     *
     * @param string $html
     * @param HTMLPurifier_Config $config
     * @param HTMLPurifier_Context $context
     * @return string
     */
    public function preFilter($html, $config, $context)
    {
        $html = preg_replace('#<iframe#i', '<img class="edIframe"', $html);
	      $html = preg_replace('/width="(.*?)"/i', 'width="' . 750 .'"', $html);
        return $html;
    }

    /**
     *
     * @param string $html
     * @param HTMLPurifier_Config $config
     * @param HTMLPurifier_Context $context
     * @return string
     */
    public function postFilter($html, $config, $context)
    {
        $post_regex = '#<img class="edIframe"([^>]+?)>#';
        return preg_replace_callback($post_regex, array($this, 'postFilterCallback'), $html);
    }

    /**
     *
     * @param array $matches
     * @return string
     */
    protected function postFilterCallback($matches)
    {
    	

        // // Domain Whitelist
        $match = preg_match('#https?://www.youtube(-nocookie)?.com/|player\.vimeo\.com/video/|edpuzzle\.com/embed/|www\.google(?:-nocookie)?\.com/maps/|www\.slideshare(?:-nocookie)?\.net/|docs\.google(?:-nocookie)?\.com/|www\.powtoon(?:-nocookie)?\.com/embed/|onedrive\.live(?:-nocookie)?\.com/|app\.emaze(?:-nocookie)?\.com/|storybird(?:-nocookie)?\.com/books/|e\.issuu\.com/|cmapscloud\.ihmc\.us/#', $matches[1]);
     
        if ($match) {

            $extra = ' webkitAllowFullScreen mozallowfullscreen allowFullScreen';
            return '<iframe ' . $matches[1] . $extra . '></iframe>';
        } else {
            return '';
        }
    }
}