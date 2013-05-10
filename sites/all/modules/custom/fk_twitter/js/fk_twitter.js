/**
 * @file
 * JavaScript behaviors for the FPL Twitter module.
 */

(function($) {
  Drupal.behaviors.fkTwitter = {
    attach: function(context, settings) {
      var rotateDelay = 10000;
      $('ul.tweets-pulled-listing', context).once('tweets', function() {
        var tweets = $('li', this);
        var x = 0;
        var last = 0;

        tweets.hide();
        tweets[0].show();

        /**
         * Creates a show/hide circular loop on the tweet
         * list items.
         */
        var loopTweets = function() {
          if (last === x) {
            if ((x + 1) === tweets.length) {
              x = 0;
            }
            else {
              x++;
            }
            return;
          }

          $(tweets[last]).fadeOut(function() {
            $(tweets[x]).fadeIn(function() {
              last = x;
              if ((x + 1) === tweets.length) {
                x = 0;
              }
              else {
                x++;
              }
            });
          });
        };

        var loop = setInterval(loopTweets, rotateDelay);

        // Pause and resume the interval on mouse in/out.
        $(this).mouseover(function() {
          clearInterval(loop);
        });
        $(this).mouseout(function() {
          loop = setInterval(loopTweets, rotateDelay);
        });
      });
    }
  };
}(jQuery));

